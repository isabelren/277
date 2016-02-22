#pragma once

#include <QTreeWidgetItem>
#include <vector>
#include "shaderprogram.h"
#include <la.h>

class Node : public QObject, public QTreeWidgetItem
{
    Q_OBJECT
public:
    enum GeomType{NULLPTR, SPHERE, CYLINDER, CUBE};
    enum TransType{NULLP, TRANSLATION, ROTATION, SCALE};
    Node();
    Node(QString name, float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz);
    ~Node();

    int childCount();
    Node* childAt(int idx);
    void addChild(QTreeWidgetItem* child);
    void removeSingleChild(QTreeWidgetItem *child);
    void takeChildren(QTreeWidgetItem* child);
    void setParent(Node* n);
    void setGeomColor(const glm::vec4& c);
    const glm::vec4& getGeometryColor() const;

    void setGeometry(ShaderProgram::Drawable* g);
    ShaderProgram::Drawable* getGeometry();

    void setTranslation(float x, float y, float z);
    void setRotation(float x, float y, float z);
    void setScale(float x, float y, float z);
    void setName(QString);
    Node* getParent();
    double getTX();
    double getTY();
    double getTZ();
    double getRX();
    double getRY();
    double getRZ();
    double getSX();
    double getSY();
    double getSZ();

    glm::mat4 getTransMat();

private:
    Node* parent;
    std::vector<Node*> children;
    ShaderProgram::Drawable* geometry;
    glm::vec4 geom_color;
    QString name;

    Node::GeomType currentGeom;

    float tx, ty, tz;
    float rx, ry, rz;
    float sx, sy, sz;


public slots:

};
