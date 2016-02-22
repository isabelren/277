#include "mygl.h"
#include <la.h>

#include <iostream>
#include <QApplication>
#include <QKeyEvent>

static const glm::vec4 WHITE = glm::vec4(1,1,1,1);
static const glm::vec4 RED = glm::vec4(1,0,0,1);
static const glm::vec4 GREEN = glm::vec4(0,1,0,1);
static const glm::vec4 BLUE  = glm::vec4(0,0,1,1);


MyGL::MyGL(QWidget *parent)
    : GLWidget277(parent)
{
}

MyGL::~MyGL()
{
    makeCurrent();

    vao.destroy();
    geom_cylinder.destroy();
    geom_sphere.destroy();
    geom_cube.destroy();
}

void MyGL::initializeGL()
{
    xPos = 0;
    yPos = 0;
    selectedColor = 0;
    nameString = "";
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

    //Create the example sphere (you should delete this when you add your own code elsewhere)
    geom_cylinder.setColor(glm::vec4(1,0,0,1));
    geom_cylinder.create();

    geom_sphere.setColor(glm::vec4(0,1,0,1));
    geom_sphere.create();

    geom_cube.setColor(glm::vec4(0,1,0,1));
    geom_cube.create();

    // Create and set up the diffuse shader
    prog_lambert.create(":/glsl/lambert.vert.glsl", ":/glsl/lambert.frag.glsl");
    // Create and set up the wireframe shader
    prog_wire.create(":/glsl/wire.vert.glsl", ":/glsl/wire.frag.glsl");

    // We have to have a VAO bound in OpenGL 3.2 Core. But if we're not
    // using multiple VAOs, we can just bind one once.
    vao.bind();

    //Create camera!
    camera = new Camera();

    //entire character10 minute hiit
    float rootX = 0.0f;
    float rootY = -50.0f;//negative angles to make character turn to its right
    float rootZ = 0.0f;

    //neck angles
    float neckXAngle = 0.0f;
    float neckYAngle = 0.0f;
    float neckZAngle = 0.0f;

    //shoulder angles
    float rShoulderXAngle = 0.0f;
    float rShoulderYAngle = 50.0f; //positive angles will make arm come forward
    float rShoulderZAngle = -20.0f; //ngeative angles will make arm go up

    float lShoulderXAngle = 0.0f;
    float lShoulderYAngle =  -50.0f; //negative angles make arm come forward
    float lShoulderZAngle = 20.0f; //positive angles make arm go up

    //elbow angles
    float rElbowXAngle = 0.0f; //positive angles make forearm come forward
    float rElbowYAngle = 0.0f;
    float rElbowZAngle = -70.0f; //negative angles make forearm go up

    float lElbowXAngle = 0.0f; //positive angles make forearm come forward
    float lElbowYAngle = 0.0f;
    float lElbowZAngle = 70.0f; //positive angles make forearm go up

    //Hip angles
    float rHipXAngle = 0.0f;//negative makes leg come forward
    float rHipYAngle = 0.0f;
    float rHipZAngle = 0.0f; //negative makes legs go outwards

    float lHipXAngle = 0.0f; //negative makes leg come forward
    float lHipYAngle = 0.0f;
    float lHipZAngle = 0.0f; //positive makes legs go outwards

    //Knee angles
    float rKneeXAngle = 0.0f; //positive < 90 makes calves go back (natural knee movement)
    float rKneeYAngle = 0.0f;
    float rKneeZAngle = 0.0f;

    float lKneeXAngle = 0.0f; //positive < 90 makes calves go back (natural knee movement)
    float lKneeYAngle = 0.0f;
    float lKneeZAngle = 0.0f;

    root = createNode("root", 0, 0, 0, rootX, rootY, rootZ, 1, 1, 1, WHITE, nullptr);
    Node* body = createNode("body", 0, 0, 0, 0, 0, 0, 1.5f, 2.5, 1.5f, RED, &geom_cylinder);

    //UNCOMMMENT HERE FOR  REST OF CHARACTER
    /*
    Node* head=createNode("head", 0, .45f, 0, 0, 0, 0, 1.5f, .87f, 1.5f, WHITE, &geom_sphere);
    Node* rEye=createNode("right eye", 0.45f, .6f, .55f, 0, 0, 0, .15f, .09f, .15f, GREEN, &geom_sphere);
    Node* lEye=createNode("left eye", -0.45f, .6f, .55f, 0, 0, 0, .15f, .09f, .15f, GREEN, &geom_sphere);
    Node* neckJoint=createNode("neck joint", 0, .5f, 0, neckXAngle, neckYAngle, neckZAngle, 1, 1, 1, RED, nullptr);

    Node* uRArm=createNode("upper right arm", -.45f, 0, 0, 0, 0, 90.0f, .2f, .9f, .3f, RED, &geom_cube); //good
    Node* rShoulderJoint=createNode("right shoulder joint", -.5f, .35f, 0, rShoulderXAngle, rShoulderYAngle, rShoulderZAngle, 1, 1, 1, RED, nullptr); //good

    Node* uLArm=createNode("upper left arm", -.45f, 0, 0, 0, 0, 90.0f, .2f, .9f, .3f, RED, &geom_cube);
    Node* lShoulderJoint=createNode("left shoulder joint", .5f, .35f, 0, lShoulderXAngle, lShoulderYAngle, 180.0f + lShoulderZAngle, 1, 1, 1, RED, nullptr);

    Node* lRArm=createNode("lower right arm", 0, .4f, 0, 0, 0, 0, .2f, .8f, .4f, WHITE, &geom_cylinder);
    Node* rElbowJoint=createNode("right elbow joint", 0, .50f, 0, rElbowXAngle, rElbowYAngle, rElbowZAngle, 1, 1, 1, RED, nullptr);

    Node* lLArm=createNode("lower left arm", 0, .4f, 0, 0, 0, 0, .2f, .8f, .4f, WHITE, &geom_cylinder);
    Node* lElbowJoint=createNode("left elbow joint", 0, .50f, 0, lElbowXAngle, lElbowYAngle, lElbowZAngle, 1, 1, 1, RED,  nullptr);

    //Legs
    Node* uLLeg=createNode("upper left leg", 0, -.35f, 0, 0, 0, 0, .3f, .7f, .3f, BLUE, &geom_cube); //good
    Node* lHipJoint=createNode("left hip joint", .3f, -.5f, 0, lHipXAngle, lHipYAngle, lHipZAngle, 1, 1, 1, BLUE, nullptr); //good

    Node* uRLeg=createNode("upper right leg", 0, -.35f, 0, 0, 0, 0, .3f, .7f, .3f, BLUE, &geom_cube);
    Node* rHipJoint=createNode("right hip joint", -.3f, -.5f, 0, rHipXAngle, rHipYAngle, rHipZAngle, 1, 1, 1, RED, nullptr);

    Node* lLLeg=createNode("lower left leg", 0, -.5f, 0, 0, 0, 0, .6f, 1, .6f, WHITE, &geom_cube);
    Node* lKneeJoint=createNode("left knee joint", 0, -.5f, 0, lKneeXAngle, lKneeYAngle, lKneeZAngle, 1, 1, 1, RED, nullptr);

    Node* lRLeg=createNode("lower right leg", 0, -.5f, 0, 0, 0, 0, .6f, 1, .6f, WHITE, &geom_cube);
    Node* rKneeJoint=createNode("right knee joint", 0, -.5f, 0, rKneeXAngle, rKneeYAngle, rKneeZAngle, 1, 1, 1, RED,  nullptr);

    root->addChild(body);

    body->addChild(neckJoint);

    //Arms
    body->addChild(rShoulderJoint);
    body->addChild(lShoulderJoint);

    neckJoint->addChild(head);
    neckJoint->addChild(rEye);
    neckJoint->addChild(lEye);

    lShoulderJoint->addChild(uLArm);
    rShoulderJoint->addChild(uRArm);

    uRArm->addChild(rElbowJoint);
    uLArm->addChild(lElbowJoint);

    rElbowJoint->addChild(lRArm);
    lElbowJoint->addChild(lLArm);

    //Legs
    body->addChild(rHipJoint);
    body->addChild(lHipJoint);

    lHipJoint->addChild(uLLeg);
    rHipJoint->addChild(uRLeg);

    uRLeg->addChild(rKneeJoint);
    uLLeg->addChild(lKneeJoint);

    rKneeJoint->addChild(lRLeg);
    lKneeJoint->addChild(lLLeg);

    selectedNode = root;
    selectedGeometry = 0;
    */

    root->addChild(body);
    //Node* test = createNode("test", 0, 0, 0, 0, 0, 0, 1, 1, 1, WHITE, &geom_cube);
    selectedNode = nullptr;
    emit sig_sendRoot(root);
}

void MyGL::resizeGL(int w, int h)
{
    camera->setWidth(w);
    camera->setHeight(h);
    //This code sets the concatenated view and perspective projection matrices used for
    //our scene's camera view.

    glm::mat4 viewproj = camera->getProjMat() * camera->getViewMat();


    // Upload the view-projection matrix to our shaders (i.e. onto the graphics card)
    QMatrix4x4 qviewproj = la::to_qmat(viewproj);

    prog_lambert.prog.bind();
    prog_lambert.prog.setUniformValue(prog_lambert.unifViewProj, qviewproj);

    prog_wire.prog.bind();
    prog_wire.prog.setUniformValue(prog_wire.unifViewProj, qviewproj);

    printGLErrorLog();
}


//This function is called by Qt any time your GL window is supposed to update
//For example, when the function updateGL is called, paintGL is called implicitly.
void MyGL::paintGL()
{
    // Clear the screen so that we only see newly drawn images
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    traverse(root, glm::mat4(1.0f));

    //Here is a good spot to call your scene graph traversal function.
}

Node* MyGL::createNode(QString name, float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz, const glm::vec4& c, ShaderProgram::Drawable* g) {
    Node* n = new Node(name, tx, ty, tz, rx, ry, rz, sx, sy, sz);
    n->setGeometry(g);
    n->setGeomColor(c);
    return n;
}

void MyGL::traverse(Node* N, glm::mat4 t)
//should t be a pointer? do i need to put MyGL:: before Traverse?
{
    glm::mat4 transformation = t * N->getTransMat();

    if (N->childCount() > 0) {
        for(int i = 0; i < N->childCount(); i++) {
            if (N == selectedNode) {
                colorChangeTraverse(N->childAt(i), transformation);
            } else {
                traverse(N->childAt(i), transformation);
            }
         }
    }
    if (N->getGeometry() != nullptr) {
        if (N==selectedNode) {
            MyGL::drawShape(N->getGeometry(), GREEN, transformation);
        } else {
            MyGL::drawShape(N->getGeometry(), N->getGeometryColor(), transformation);
        }
    }
}

void MyGL::colorChangeTraverse(Node* c, glm::mat4 t)
{
    glm::mat4 transformation = t * c->getTransMat();

    if (c->childCount() > 0) {
        for(int i = 0; i < c->childCount(); i++) {
            colorChangeTraverse(c->childAt(i), transformation);
         }
    }

    if (c->getGeometry() != nullptr) {
        MyGL::drawShape(c->getGeometry(), GREEN, transformation);
    }
}

void MyGL::drawShape(ShaderProgram::Drawable* shape, glm::vec4 color, glm::mat4 transformation)
{
    prog_lambert.setModelMatrix(transformation);
    shape->setColor(color);
    prog_lambert.draw(*this, *shape);
}

void MyGL::repaint()
{
    MyGL::resizeGL(camera->getWidth(), camera->getHeight());
}

void MyGL::keyPressEvent(QKeyEvent *e)
{
    // http://doc.qt.io/qt-5/qt.html#Key-enum
    if (e->key() == Qt::Key_Escape) {
        QApplication::quit();
    }

    if (e->key() == Qt::Key_Left) {
        camera->setTheta(camera->getTheta() - 1.0f);
        MyGL::repaint();
    }

    if (e->key() == Qt::Key_Right) {
        camera->setTheta(camera->getTheta() + 1.0f);
        MyGL::repaint();
    }

    if (e->key() == Qt::Key_Up) {
        camera->setPhi(camera->getPhi() + 0.1f);
        MyGL::repaint();
    }

    if (e->key() == Qt::Key_Down) {
        camera->setPhi(camera->getPhi() - 1.0f);
        MyGL::repaint();
    }

    if (e->key() == Qt::Key_Plus) {
        camera->setZoom(camera->getZoom() + 1.0f);
        MyGL::repaint();
    }

    if (e->key() == Qt::Key_Minus) {
        camera->setZoom(camera->getZoom() - 1.0f);
        MyGL::repaint();
    }

}

void MyGL::mousePressEvent (QMouseEvent * event) {
    xPos = event->x();
    yPos = event->y();
}

void MyGL::mouseMoveEvent (QMouseEvent * event) {
    if(event->buttons() & Qt::LeftButton)
     {
        camera->setPhi(camera->getPhi() + .0001 * (event->y() + yPos));
        camera->setTheta(camera->getTheta() + .0001 * (event->x() + xPos));
        MyGL::repaint();
      }
}

//change colors of current node!!
void MyGL::slot_changeCurrentNode(QTreeWidgetItem* q)
{
    selectedNode = (Node*)q;
    MyGL::repaint();
}

void MyGL::slot_changeColor(int i) {
    selectedColor = i;
}

void MyGL::slot_changeGeom(int i) {
    selectedGeometry = i;
}

void MyGL::slot_changeNameString(QString s){
    nameString = s;
}

void MyGL::slot_rename()
{
    emit sig_rename(nameString);
}


void MyGL::slot_addNewNode() {
    ShaderProgram::Drawable* shape;
    Node* n;
    switch (selectedGeometry) {
    case 0: //NULLPTR
        shape = nullptr;
        break;
    case 1: //SPHERE
        shape = &geom_sphere;
        break;
    case 2:
        shape = &geom_cylinder;
        break;
    case 3:
        shape = &geom_cube;
        break;
    };

    switch (selectedColor) {
        case 0:
            n = createNode("untitled", 0, 0, 0, 0, 0, 0, 1, 1, 1, WHITE, shape);
            break;
        case 1:
            n = createNode("untitled", 0, 0, 0, 0, 0, 0, 1, 1, 1, RED, shape);
            break;
        case 2: //BLUE
            n = createNode("untitled", 0, 0, 0, 0, 0, 0, 1, 1, 1, BLUE, shape);
            break;

    }
    selectedNode->addChild(n);
    MyGL::repaint();
}
