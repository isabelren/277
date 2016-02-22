#pragma once
#include <scene/geometry.h>
#include <QVector>
#include <la.h>
#include <scene/skeleton.h>
#include <unordered_map>

class Vertex
{
public:
    Vertex(const glm::vec3 &pos);
    Vertex();
    glm::vec3 position;
    std::unordered_map<Joint*, float> jointInfluences;
    int numInfluencers;
};

class Face
{
public:
    Face(int idx1, int idx2, int idx3);
    Face();
    int vertices[3];
};

class Mesh : public Geometry
{
public:
    Mesh();
    virtual ~Mesh(){}
    virtual void create();
    bool LoadOBJ(const QString &filepath);
    void skinMesh(Skeleton*);
    float getDistance(int vertIdx, Joint* joint);
    bool skinned;
    void linearBlendSkinning();
private:
    QVector<Face> faces;
    QVector<Vertex> vertices;
    //When computing the normal of a Face for its VBOs, just take the cross product of two of its edges.
    //No need to store the normals unless you want smooth-looking surfaces
};
