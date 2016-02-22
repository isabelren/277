#include "mygl.h"
#include <la.h>

#include <iostream>
#include <QApplication>
#include <QKeyEvent>
#include <QFileDialog>
#include <QTextStream>
#include "glm/ext.hpp"
#include <iostream>
using namespace std;

static const glm::vec4 WHITE = glm::vec4(1,1,1,1);
static const glm::vec4 RED = glm::vec4(1,0,0,1);
static const glm::vec4 GREEN = glm::vec4(0,1,0,1);
static const glm::vec4 BLUE  = glm::vec4(0,0,1,1);

MyGL::MyGL(QWidget *parent)
    : GLWidget277(parent), mesh(nullptr)
{
    setFocusPolicy(Qt::StrongFocus);
}

MyGL::~MyGL()
{
    makeCurrent();

    vao.destroy();
    geom_cylinder.destroy();
    geom_sphere.destroy();
    geom_joint.destroy();
}

void MyGL::initializeGL()
{

    // Create an OpenGL context
    initializeOpenGLFunctions();
    // Print out some information about the current OpenGL context
    debugContextVersion();

    // Set a few settings/modes in OpenGL rendering
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    // Set the size with which points should be rendered
    glPointSize(5);
    // Set the color with which the screen is filled at the start of each render call.
    glClearColor(0.5, 0.5, 0.5, 1);

    printGLErrorLog();

    // Create a Vertex Attribute Object
    vao.create();
    selectedJoint = nullptr;
    skeleton = nullptr;
    //Create the example sphere (you should delete this when you add your own code elsewhere)
    geom_cylinder.setColor(glm::vec4(1,0,0,1));
    geom_cylinder.create();

    geom_sphere.setColor(glm::vec4(0,1,0,1));
    geom_sphere.create();

    geom_joint.setColor(glm::vec4(1,1,1,1));
    geom_joint.create();

    // Create and set up the diffuse shader

    prog_lambert.create(":/glsl/lambert.vert.glsl", ":/glsl/lambert.frag.glsl");
    // Create and set up the wireframe shader
    prog_wire.create(":/glsl/wire.vert.glsl", ":/glsl/wire.frag.glsl");
    //Create and set up the skin deformer shader
    prog_skin.create(":/deform.vert", ":/deform.frag");

    // We have to have a VAO bound in OpenGL 3.2 Core. But if we're not
    // using multiple VAOs, we can just bind one once.
    vao.bind();
}

void MyGL::updateCamera()
{
    camera.recompute(this->width(), this->height());
    glm::mat4 viewproj = camera.viewProj();

    // Upload the view-projection matrix to our shaders (i.e. onto the graphics card)
    QMatrix4x4 qviewproj = la::to_qmat(viewproj);

    prog_lambert.prog.bind();
    prog_lambert.prog.setUniformValue(prog_lambert.unifViewProj, qviewproj);

    QVector4D eye = la::to_qvec(glm::vec4(camera.eye, 1.0f));
    prog_lambert.prog.setUniformValue(prog_lambert.unifEye, eye);

    prog_wire.prog.bind();
    prog_wire.prog.setUniformValue(prog_wire.unifViewProj, qviewproj);

    prog_skin.prog.bind();
    prog_skin.prog.setUniformValue(prog_skin.unifViewProj, qviewproj);

    prog_skin.prog.setUniformValue(prog_skin.unifEye, eye);

    printGLErrorLog();
}

void MyGL::resizeGL(int w, int h)
{
    updateCamera();
}

//This function is called by Qt any time your GL window is supposed to update
//For example, when the function updateGL is called, paintGL is called implicitly.
//update() is no longer called by a timer in GLWidget277; it must be called manually as in keyPressEvent
void MyGL::paintGL()
{
    // Clear the screen so that we only see newly drawn images
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    updateCamera();

    if(mesh != nullptr)
    {
        if (mesh->skinned) {
            QMatrix4x4 *matrices = new QMatrix4x4[100];

            for (int i = 0; i < this->skeleton->getChildrenCount(); i++) {
                matrices[i] = la::to_qmat(this->skeleton->getChildAt(i)->getOverallTransformation());
            }
            prog_skin.setModelMatrix(glm::mat4(1.0f));
            prog_skin.setTransMatrices(matrices);
            prog_skin.draw(*this, *mesh);
        } else {
           prog_lambert.setModelMatrix(glm::mat4(1.0f));
           prog_lambert.draw(*this, *mesh);
        }

    }
    glDisable(GL_DEPTH_TEST);
    if(skeleton != nullptr)
    {
        if (skeleton->exists()) {
            glm::mat4 transform;
            for (int i = 0; i < skeleton->getChildrenCount(); i++) {
                transform = skeleton->getChildAt(i)->getOverallTransformation();
                prog_wire.setModelMatrix(transform);
                if (selectedJoint != nullptr && skeleton->getChildAt(i)->getName().compare(selectedJoint->getName()) == 0) {
                    Joint* j = new Joint(1);
                    j->create();
                    prog_wire.setModelMatrix(transform);
                    prog_wire.draw(*this, *j);
                } else {
                    prog_wire.draw(*this, geom_joint);
                }
            }

            for (int i = 0; i < skeleton->getBoneCount(); i++) {
                Bone* bone = skeleton->getBoneAt(i);
                if (bone != nullptr) {
                    bone->create();
                    prog_wire.setModelMatrix(glm::mat4(1.0f));
                    prog_wire.draw(*this, *bone);
                }

            }
            if (selectedJoint != nullptr) {

            }
        }

    }
    glEnable(GL_DEPTH_TEST);
}

void MyGL::keyPressEvent(QKeyEvent *e)
{
    // http://doc.qt.io/qt-5/qt.html#Key-enum
    switch (e->key()) {
    case Qt::Key_Escape: QApplication::quit(); break;
    case Qt::Key_Up:
        camera.phi -= 5.0f;
        update();
        break;
    case  Qt::Key_Down:
        camera.phi += 5.0f;
        update();
        break;
    case Qt::Key_Left:
        camera.theta -= 5.0f;
        update();
        break;
    case Qt::Key_Right:
        camera.theta += 5.0f;
        update();
        break;

    default:
        break;
    }
}

void MyGL::slot_update()
{
    update();
}

void MyGL::slot_LoadOBJ()
{
    QString filepath = QFileDialog::getOpenFileName(0, QString("Load OBJ"), QString(), QString("*.obj"));
    if(filepath.length() == 0)
    {
        return;
    }
    delete mesh;
    mesh = new Mesh();
    bool successful = mesh->LoadOBJ(filepath);
    if(!successful)
    {
        delete mesh;
        mesh = nullptr;
    }
    update();
}

void MyGL::slot_LoadJSON()
{
    QString filepath = QFileDialog::getOpenFileName(0, QString("Load JSON"), QString(), QString("*.json"));
    if(filepath.length() == 0)
    {
        return;
    }
    delete skeleton;
    skeleton = new Skeleton();
    bool successful = skeleton->LoadJSON(filepath);
    if(!successful)
    {
        delete skeleton;
        skeleton = nullptr;
    } else {
        emit sig_sendRoot(this->skeleton->getRoot());
    }
    update();
}

void MyGL::slot_skinMesh() {
    if (mesh != nullptr) {
        this->mesh->skinMesh(this->skeleton);

        QMatrix4x4* matrices = new QMatrix4x4[100];
        for (int i = 0; i < this->skeleton->getChildrenCount(); i++) {
            matrices[i] = la::to_qmat(this->skeleton->getChildAt(i)->getBindMatrix());
        }

        prog_skin.setBindMatrices(matrices);
    }


}


void MyGL::slot_updateCurrentJoint(Joint* j) {
    selectedJoint = j;
    update();
}

void MyGL::slot_moveMesh()
{
    if (mesh != nullptr) {
        this->mesh->linearBlendSkinning();

        update();
    }

}
