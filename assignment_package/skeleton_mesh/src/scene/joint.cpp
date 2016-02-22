#include "joint.h"
#include <la.h>
#include <iostream>

 //3 circles, 12 each
static const int JOINT_VERT_COUNT = 36;

Joint::Joint() : Geometry()
{
    tx = ty = tz = angle = axis_x = axis_y = axis_z = 0;
    setRotation();
    parent = nullptr;
    name="untitled";
    QTreeWidgetItem::setText(0, name);
    bound = false;
}

Joint::Joint(int indicator)
{
    this->selected = indicator;
    bound = false;
}

Joint::Joint(QString name, float tx, float ty, float tz, float angle, float axis_x, float axis_y, float axis_z)
{
    bound = false;
    this->name = name;
    this->tx = tx; this->ty = ty; this->tz = tz;
    this->angle = angle;
    this->axis_x= axis_x; this->axis_y= axis_y; this->axis_z= axis_z;

    this->rotationQuat = glm::angleAxis(angle, glm::vec3(axis_x, axis_y, axis_z));
    this->rotationMat = glm::mat4_cast(rotationQuat);

    QTreeWidgetItem::setText(0, name);
    parent = nullptr;
}

Joint::~Joint()
{

    while(children.size() > 0){
        delete children[0];
        children.erase(children.begin());
    }
}

void createJointVertexPositions(glm::vec4 (&joint_vert_pos)[JOINT_VERT_COUNT]) {
    //create 3 rings
    glm::vec4 v;

    //x axis
    for(int i = 0; i < 12; i++) {
        v = glm::rotate(glm::mat4(1.0f), i*30.0f, glm::vec3(1, 0, 0)) * glm::vec4(0.0f,0.5f,0,1);
        joint_vert_pos[i] = v;
    }

    //y axis
    for(int i = 12; i < 24; i++) {
        v = glm::rotate(glm::mat4(1.0f), (i-12) * 30.0f, glm::vec3(0,1,0)) * glm::vec4(0.5f,0,0,1);
        joint_vert_pos[i] = v;
    }

    //z axis
    for(int i = 24; i < 36; i++) {
        v = glm::rotate(glm::mat4(1.0f), (i-24) * 30.0f, glm::vec3(0,0,1)) * glm::vec4(0,0.5f,0,1);
        joint_vert_pos[i] = v;
    }
}

void createJointIndices(GLuint (&joint_idx)[JOINT_IDX_COUNT]) {
    for(int i = 0; i < 11; i++) {
        joint_idx[i*2] = i;
        joint_idx[i*2 + 1] = i + 1;
        joint_idx[24 + i*2] = 12 + i;
        joint_idx[24 + i*2 + 1] = 12 + i + 1;
        joint_idx[48 + i*2] = 24 + i;
        joint_idx[48 + i*2 + 1] = 24 + i + 1;
    }
    joint_idx[22] = 0;
    joint_idx[23] = 11;
    joint_idx[46] = 12;
    joint_idx[47] = 23;
    joint_idx[70] = 24;
    joint_idx[71] = 35;
}

GLenum Joint::drawMode()
{
   return GL_LINES;
}

void Joint::createColorIdx(glm::vec4 (&joint_col)[JOINT_IDX_COUNT]){
    for (int i = 0; i < JOINT_IDX_COUNT; i++) {
        joint_col[i] = glm::vec4(0,1,0,1);
    }
}

void Joint::create()
{
    GLuint joint_idx[JOINT_IDX_COUNT];
    glm::vec4 joint_vert_pos[JOINT_VERT_COUNT];
    glm::vec4 joint_col[JOINT_IDX_COUNT];

    createJointVertexPositions(joint_vert_pos);
    createJointIndices(joint_idx);
    createColorIdx(joint_col);

    count = JOINT_IDX_COUNT;

    //QOpenGLBuffer Class
    bufIdx.create();
    bufIdx.bind();
    bufIdx.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufIdx.allocate(joint_idx, JOINT_IDX_COUNT * sizeof(GLuint));

    //sending array of information to graphics card
    bufPos.create();
    bufPos.bind();
    bufPos.setUsagePattern(QOpenGLBuffer::StaticDraw);
    //joint_VERT_COUNT is malloc-ing; putting joint_vert_pos in
    bufPos.allocate(joint_vert_pos,JOINT_VERT_COUNT * sizeof(glm::vec4));

    if (selected == 1) {
        bufCol.create();
        bufCol.bind();
        bufCol.setUsagePattern(QOpenGLBuffer::StaticDraw);
        //joint_VERT_COUNT is malloc-ing; putting joint_vert_pos in
        bufCol.allocate(joint_col,JOINT_IDX_COUNT * sizeof(glm::vec4));
    }
}

void Joint::setRotation()
{
     this->rotationMat = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(axis_x, axis_y, axis_z));
     this->rotationQuat = glm::quat_cast(this->rotationMat);
}

int Joint::childCount()
{
    return children.size();
}

Joint* Joint::childAt(int idx)
{
    if (idx < children.size()) {
        return children[idx];
    }
    return nullptr;
}

void Joint::addChild(QTreeWidgetItem *child)
{
    QTreeWidgetItem::addChild(child);
    Joint* j = (Joint*)child;
    children.push_back(j);
    j->setParent(this);
}

void Joint::setParent(Joint* j)
{
    parent = j;
}

Joint* Joint::getParent()
{
    return this->parent;
}

QString Joint::getName()
{
    return this->name;
}

glm::vec3 Joint::getEulers()
{
    return glm::eulerAngles(this->rotationQuat);
}

double Joint::getTX()
{
    return this->tx;
}

double Joint::getTY()
{
    return this->ty;
}

double Joint::getTZ()
{
    return this->tz;
}

void Joint::setTransformation(float tx, float ty, float tz)
{
    this->tx = tx;
    this->ty = ty;
    this->tz = tz;
}

glm::mat4 Joint::getBindMatrix()
{
    if (this->bound == true) {
        return this->bindMatrix;
    } else {
        return glm::mat4(1.0f);
    }
}

void Joint::setBindMatrix()
{
   this->bindMatrix = glm::inverse(getOverallTransformation());
   this->bound = true;
}

glm::mat4 Joint::getLocalTransformation()
{

    glm::mat4 T = glm::translate(glm::mat4(1.0f), glm::vec3(tx, ty, tz));
    return T * glm::mat4_cast(this->rotationQuat);
}

glm::vec4 Joint::getPos()
{
    return getOverallTransformation() * glm::vec4(0,0,0,1);
}

glm::mat4 Joint::getOverallTransformation()
{
    Joint* currentParent = getParent();

    glm::mat4 overallTransform = this->getLocalTransformation();
    while (currentParent != nullptr) {
        overallTransform = currentParent->getLocalTransformation() * overallTransform;
        currentParent = currentParent->getParent();
    }

    return overallTransform;
}

void Joint::concatRotation(glm::quat rot) {
    //set rotation matrix and quarternion
    this->rotationQuat = rot * this->rotationQuat;
    this->rotationMat = glm::mat4_cast(rotationQuat);
}
