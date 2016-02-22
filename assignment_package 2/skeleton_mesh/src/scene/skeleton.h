#pragma once

#include <scene/geometry.h>
#include <scene/joint.h>
#include <scene/bone.h>
#include <vector>
#include "shaderprogram.h"
#include <la.h>
#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <scene/geometry.h>
#include <vector>

//stores all vertex data of a large set of VBOs
class Skeleton
{
public:
    Skeleton();
    Skeleton(Joint* root);
    ~Skeleton();
    Joint* getRoot();
    Joint* traverseJSON(const QJsonObject &current);
    bool LoadJSON(const QString &filepath);
    int getChildrenCount();
    Joint* getChildAt(int i);
    int getBoneCount();
    Bone* getBoneAt(int i);
    bool exists();


private:
    Joint* root;
    std::vector<Joint*> children;
    std::vector<Bone*> bones;
    bool skel_exists;


};

