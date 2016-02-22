#ifndef MYGL_H
#define MYGL_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <glwidget277.h>
#include <utils.h>
#include <shaderprogram.h>
#include <scene/cylinder.h>
#include <scene/sphere.h>
#include <camera.h>
#include <scene/mesh.h>
#include <scene/joint.h>
#include <scene/skeleton.h>


#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>


class MyGL
    : public GLWidget277
{
    Q_OBJECT
private:
    QOpenGLVertexArrayObject vao;

    Cylinder geom_cylinder;//The instance of a unit cylinder we can use to render any cylinder
    Sphere geom_sphere;//The instance of a unit sphere we can use to render any sphere
    Joint geom_joint;//instance of a joint we can use to render any joint
    Joint geom_selected;

    ShaderProgram prog_lambert;
    ShaderProgram prog_wire;
    ShaderProgram prog_skin;

    Camera camera;
    Mesh* mesh;
    Skeleton* skeleton;
    Joint* selectedJoint;
    bool dual;

public:
    explicit MyGL(QWidget *parent = 0);
    ~MyGL();

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void updateCamera();

protected:
    void keyPressEvent(QKeyEvent *e);

public slots:
    void slot_LoadOBJ();
    void slot_LoadJSON();
    void slot_skinMesh();
    void slot_update();
    void slot_updateCurrentJoint(Joint*);
    void slot_moveMesh();
    void slot_dualQuat();
    void slot_linearBlend();
signals:
    void sig_sendRoot(QTreeWidgetItem*);
};


#endif // MYGL_H
