#ifndef MYGL_H
#define MYGL_H

#include <glwidget277.h>
#include <utils.h>
#include <shaderprogram.h>
#include <scene/cylinder.h>
#include <scene/sphere.h>
#include <scene/cube.h>
#include <scene/node.h>
#include <scene/camera.h>

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
    Cube geom_cube; //unit cube
    ShaderProgram prog_lambert;
    ShaderProgram prog_wire;
    Node* root;
    Camera* camera;
    int xPos;
    int yPos;


    //current node selected on QTreeWidget
    Node* selectedNode;

    //current geometry
    int selectedGeometry;
    int selectedColor;
    QString nameString;

public:
    explicit MyGL(QWidget *parent = 0);
    ~MyGL();

    void initializeGL();
    void resizeGL(int w, int h);
    Node* createNode(QString, float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz, const glm::vec4& c, ShaderProgram::Drawable* g);
    void traverse(Node* N, glm::mat4 t);
    void colorChangeTraverse(Node*, glm::mat4);
    void drawShape(ShaderProgram::Drawable* shape, glm::vec4 color, glm::mat4 transformation);
    void paintGL();
    void repaint();

public slots:
    void slot_changeCurrentNode(QTreeWidgetItem*);
    void slot_changeGeom(int i);
    void slot_changeColor(int i);
    void slot_changeNameString(QString s);
    void slot_rename();
    void slot_addNewNode();
signals:
    void sig_sendRoot(QTreeWidgetItem*);
    void sig_nodeGeom(ShaderProgram::Drawable*);
    void sig_rename(QString);

protected:
    void keyPressEvent(QKeyEvent *e);
    void mouseMoveEvent (QMouseEvent * event);
    void mousePressEvent (QMouseEvent * event);
};


#endif // MYGL_H
