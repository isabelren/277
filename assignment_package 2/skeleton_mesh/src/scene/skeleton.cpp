#include "skeleton.h"
#include <QString>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <la.h>
#include <QJsonDocument>
#include <QTextStream>


static const glm::vec4 WHITE = glm::vec4(1,1,1,1);
static const glm::vec4 RED = glm::vec4(1,0,0,1);
static const glm::vec4 GREEN = glm::vec4(0,1,0,1);
static const glm::vec4 BLUE  = glm::vec4(0,0,1,1);

Skeleton::Skeleton()
{
    skel_exists = false;
}

Skeleton::Skeleton(Joint* root)
{
   this->root = root;
}

Skeleton::~Skeleton()
{
    this->root = nullptr;
}

Joint* Skeleton::getRoot() {
    return root;
}

int Skeleton::getChildrenCount(){
    return this->children.size();
}

Joint* Skeleton::getChildAt(int i) {
    if (i < children.size()) {
        return children[i];
    }
    return nullptr;
}

int Skeleton::getBoneCount(){
    return this->bones.size();
}

Bone* Skeleton::getBoneAt(int i) {
    if (i < bones.size()) {
        return bones[i];
    }
    return nullptr;
}
Joint* Skeleton::traverseJSON(const QJsonObject &current) {
    QString name = (current["name"]).toString();
    QJsonArray pos = current["pos"].toArray();
    QJsonArray rot = current["rot"].toArray();
    QJsonArray jchildren = current["children"].toArray();
    float tx = (float)pos[0].toDouble();
    float ty = (float)pos[1].toDouble();
    float tz = (float)pos[2].toDouble();
    float angle = (float)rot[0].toDouble();
    float axis_x = (float)rot[1].toDouble();
    float axis_y = (float)rot[2].toDouble();
    float axis_z = (float)rot[3].toDouble();


    Joint* currentJoint = new Joint(name, tx, ty, tz, angle, axis_x, axis_y, axis_z);

    for (int i = 0; i < jchildren.size(); i++) {
        Joint* toAdd = traverseJSON(jchildren[i].toObject());
        Bone* newBone = new Bone(currentJoint, toAdd);
        currentJoint->addChild(toAdd);
        this->bones.push_back(newBone);
    }
    this->children.push_back(currentJoint);
    return currentJoint;
}

bool Skeleton::LoadJSON(const QString &filepath)
{
    skel_exists = true;
    //Each shape_t is a mesh within the OBJ file. The OBJs we provide only contain one shape each
    //The OBJ's materials are not handled by this loader
    QFile file;
    file.setFileName(filepath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString contents = file.readAll();
    file.close();

    if (contents.length() > 0) {
        QJsonDocument d = QJsonDocument::fromJson(contents.toUtf8());
        QJsonObject jsonObject = d.object();
        if (!jsonObject["root"].isNull()) {
            QJsonObject rootJson = jsonObject["root"].toObject();
            this->root = traverseJSON(rootJson);
        }
        return true;
    }
    return false;
}

bool Skeleton::exists()
{
    return this->skel_exists;
}
