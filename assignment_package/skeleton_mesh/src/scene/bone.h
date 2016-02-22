#pragma once

#include <scene/geometry.h>
#include <scene/joint.h>
#include <vector>
#include "shaderprogram.h"
#include <la.h>
#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <scene/geometry.h>
#include <vector>

//stores all vertex data of a large set of VBOs
class Bone : public Geometry
{
public:
    Bone();
    Bone(Joint* parent, Joint* child);
    ~Bone();

    void createBoneVertexPositions(glm::vec4 (&bone_vert_pos)[2]);
    void createBoneIndices(GLuint (&bone_idx)[2], glm::vec4 (&bone_col)[2]);
    virtual void create();
    virtual GLenum drawMode();

private:
    Joint* parent;
    Joint* child;


};

