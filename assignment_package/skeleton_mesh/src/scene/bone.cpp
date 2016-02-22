#include "bone.h"
#include <QString>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <la.h>
#include <QJsonDocument>
#include <QTextStream>


Bone::Bone()
{

}

Bone::Bone(Joint* parent, Joint* child) {
    this->parent = parent;
    this->child = child;
}

Bone::~Bone() {

}

void Bone::createBoneVertexPositions(glm::vec4 (&bone_vert_pos)[2]) {
    bone_vert_pos[0] = parent->getPos();
    bone_vert_pos[1] = child->getPos();
    count+=2;
}

void Bone::createBoneIndices(GLuint (&bone_idx)[2], glm::vec4 (&bone_col)[2]) {
    bone_idx[0] = 0;
    bone_idx[1] = 1;

    bone_col[0] =  glm::vec4(0,0,1,1);
    bone_col[1] =  glm::vec4(1,0,0,1);
}

GLenum Bone::drawMode()
{
   return GL_LINES;
}

void Bone::create()
{

    GLuint bone_idx[2];
    glm::vec4 bone_col[2];
    glm::vec4 bone_vert_pos[2];

    count = 0;
    createBoneVertexPositions(bone_vert_pos);
    createBoneIndices(bone_idx, bone_col);

    bufPos.create();
    bufPos.bind();
    bufPos.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufPos.allocate(bone_vert_pos, 2 * sizeof(glm::vec4));

    bufIdx.create();
    bufIdx.bind();
    bufIdx.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufIdx.allocate(bone_idx, 2 * sizeof(GLuint));

    bufCol.create();
    bufCol.bind();
    bufCol.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufCol.allocate(bone_col, 2  * sizeof(glm::vec4));
}


