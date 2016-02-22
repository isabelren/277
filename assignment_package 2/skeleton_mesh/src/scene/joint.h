#pragma once

#include <scene/geometry.h>
#include <QTreeWidgetItem>
#include <vector>
#include "shaderprogram.h"
#include <la.h>
#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <shaderprogram.h>

static const int JOINT_IDX_COUNT = 72;

class Joint : public QTreeWidgetItem, public Geometry
{
public:
    Joint();
    Joint(int);
    Joint(QString name, float tx, float ty, float tz, float angle, float axis_x, float axis_y, float axis_z);
    ~Joint();

    void createColorIdx(glm::vec4 (&joint_col)[JOINT_IDX_COUNT]);
    virtual void create();

    virtual GLenum drawMode();

    void setRotation();
    int childCount();
    Joint* childAt(int idx);
    void addChild(QTreeWidgetItem *child);
    void setParent(Joint* j);
    Joint* getParent();

    glm::mat4 getBindMatrix();
    void setBindMatrix();
    glm::mat4 getLocalTransformation();
    glm::mat4 getOverallTransformation();
    void concatRotation(glm::quat);
    glm::vec4 getPos();
    QString getName();
    glm::vec3 getEulers();

    double getTX();
    double getTY();
    double getTZ();
    void setTransformation(float tx, float ty, float tz);

private:
    bool bound;
    int selected;
    std::vector<Joint*> children;

    QString name;
    Joint* parent;

    float tx, ty, tz;
    float ex, ey, ez;
    float angle, axis_x, axis_y, axis_z;

    //ROTATION QUARTERNION MATRIX
    glm::quat rotationQuat;
    glm::mat4 rotationMat;
    glm::mat4 bindMatrix;

};

