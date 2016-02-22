#include <scene/mesh.h>
#include <tinyobj/tiny_obj_loader.h>
#include <iostream>
#include <unordered_map>

Mesh::Mesh() : Geometry()
{
}

Vertex::Vertex(const glm::vec3 &pos)
    : position(pos)
{}

Vertex::Vertex() : Vertex(glm::vec3(0)) {}

Face::Face(int idx1, int idx2, int idx3)
    : vertices {idx1, idx2, idx3}
{}

Face::Face() : Face(-1,-1,-1) {}

void Mesh::create()
{
    this->skinned = false;
    std::vector<GLuint> idx;
    std::vector<glm::vec4> pos;
    std::vector<glm::vec4> nor;



    GLuint index = 0;
    for(Face f : faces)
    {
        glm::vec3 p0, p1, p2;
        p0 = this->vertices[f.vertices[0]].position;
        p1 = this->vertices[f.vertices[1]].position;
        p2 = this->vertices[f.vertices[2]].position;

        //finding normal for each face
        glm::vec3 e1 = p0 - p1;
        glm::vec3 e2 = p1 - p2;
        glm::vec4 n = glm::vec4(glm::cross(e1, e2), 0.0f);

        for(int i = 0; i < 3; i++)
        {
            idx.push_back(index++);
            pos.push_back(glm::vec4(this->vertices[f.vertices[i]].position, 1.0f));
            nor.push_back(n);
        }
    }

    count = idx.size();

    this->color = glm::vec4(1.0f, 0.5f, 0.75f, 1.0f);

    bufIdx.create();
    bufIdx.bind();
    bufIdx.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufIdx.allocate(idx.data(), idx.size() * sizeof(GLuint));

    bufPos.create();
    bufPos.bind();
    bufPos.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufPos.allocate(pos.data(), pos.size() * sizeof(glm::vec4));

    bufNor.create();
    bufNor.bind();
    bufNor.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufNor.allocate(nor.data(), nor.size() * sizeof(glm::vec4));


}

//Loads an OBJ file from the input filepath and converts it to a triangulated mesh.
bool Mesh::LoadOBJ(const QString &filepath)
{
    //Each shape_t is a mesh within the OBJ file. The OBJs we provide only contain one shape each
    //The OBJ's materials are not handled by this loader
    std::vector<tinyobj::shape_t> shapes; std::vector<tinyobj::material_t> materials;
    std::string errors = tinyobj::LoadObj(shapes, materials, filepath.toStdString().c_str());
    std::cout << errors << std::endl;
    if(errors.size() == 0)
    {
        //Read the information from the vector of shape_ts
        for(unsigned int i = 0; i < shapes.size(); i++)
        {
            std::vector<float> &positions = shapes[i].mesh.positions;
            //Fill our Mesh's list of vertices
            for(unsigned int j = 0; j < positions.size(); j+=3)
            {
                this->vertices.append(Vertex(glm::vec3(positions[j], positions[j+1], positions[j+2])));
            }

            //You may add normals and UV coordinates to your meshes if you like, but they are not required
            std::vector<float> &normals = shapes[i].mesh.normals;
            std::vector<float> &uvs = shapes[i].mesh.texcoords;

            //Tell our faces which vertices they use
            std::vector<unsigned int> &indices = shapes[i].mesh.indices;
            for(unsigned int j = 0; j < indices.size(); j += 3)
            {
                this->faces.append(Face(indices[j], indices[j+1], indices[j+2]));
            }
        }
        create();
        return true;
        //If you wish, you may try to implement .mtl file loading
    }
    else
    {
        //An error loading the OBJ occurred!
        std::cout << errors << std::endl;
        return false;
    }
}

float Mesh::getDistance(int vertIdx, Joint* joint) {
    Vertex v = vertices[vertIdx];
    glm::vec4 j = joint->getPos();
    double xd = (double)(v.position[0] - j[0]) * (v.position[0] - j[0]);
    double yd = (double)(v.position[1] - j[1]) * (v.position[1] - j[1]);
    double zd = (double)(v.position[2] - j[2]) * (v.position[2] - j[2]);
    double mySqr = xd + yd + zd;
    double myDistance = sqrt(mySqr);
    return (float)myDistance;
}

void Mesh::skinMesh(Skeleton* skeleton)
{
    std::vector<glm::vec2> id;
    std::vector<glm::vec2> weights;

    //change size of jointToDistance to modify number of influencers
    std::pair<Joint*, float> jointToDistance[2];
    int idxLarger;
    Joint* joint;
    for (int j = 0; j < skeleton->getChildrenCount(); j++) {
        skeleton->getChildAt(j)->setBindMatrix();
    }

    for (int i = 0; i < vertices.size(); i++) {

        if (skeleton->getChildrenCount() > 2) {
            joint = skeleton->getChildAt(0);
            jointToDistance[0] = std::make_pair(joint, getDistance(i, joint));
            joint = skeleton->getChildAt(1);
            jointToDistance[1] = std::make_pair(joint, getDistance(i, joint));



            for (int j = 2; j < skeleton->getChildrenCount(); j++) {
                joint = skeleton->getChildAt(j);

                //get distnace of new point
                float distance = getDistance(i, joint);

                //gets index of larger element
                if (jointToDistance[0].second > jointToDistance[1].second) {
                    idxLarger = 0;
                } else {
                    idxLarger = 1;
                }

                //replaces the larger element if distance of new joint is smaller
                if (distance < jointToDistance[idxLarger].second) {
                    jointToDistance[idxLarger] = std::make_pair(skeleton->getChildAt(j), distance);
                }
            }
            //ADD TWO JOINTS TO MAP
            float summedDistance = 0;
            for (int k = 0; k < 2; k++) {
                summedDistance += jointToDistance[k].second;
            }
            if (summedDistance == 0) {
                summedDistance = 1;
            }

            for (int k = 0; k < 2; k++) {
                 vertices[i].jointInfluences.insert(std::make_pair(jointToDistance[k].first, (jointToDistance[k].second / summedDistance)));

            }

            //ADDING IDS FOR SHADER
            id.push_back(glm::vec2(skeleton->findID(jointToDistance[0].first), skeleton->findID(jointToDistance[1].first)));
            //ADDING WEIGHTS FOR SHADER
            weights.push_back(glm::vec2(jointToDistance[0].second/summedDistance, jointToDistance[1].second/summedDistance));
        } else if (skeleton->getChildrenCount() == 2) {
            //ADD TWO JOINTS
            float summedDistance = getDistance(i, skeleton->getChildAt(0)) + getDistance(i, skeleton->getChildAt(1));
            vertices[i].jointInfluences.insert(std::make_pair(skeleton->getChildAt(0), getDistance(i, skeleton->getChildAt(0))/summedDistance));
            vertices[i].jointInfluences.insert(std::make_pair(skeleton->getChildAt(1), getDistance(i, skeleton->getChildAt(1))/summedDistance));
            id.push_back(glm::vec2(0, 1));
            weights.push_back(glm::vec2(getDistance(i, skeleton->getChildAt(0))/getDistance(i, skeleton->getChildAt(0)), getDistance(i, skeleton->getChildAt(1))/summedDistance));
        }
    }

    bufID.create();
    bufID.bind();
    bufID.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufID.allocate(id.data(), id.size() * sizeof(glm::vec2));

    bufWeights.create();
    bufWeights.bind();
    bufWeights.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufWeights.allocate(weights.data(), weights.size() * sizeof(glm::vec2));
    this->skinned = true;
}

//call this function each time a joint moves (all slots that move rotation or translation)

void Mesh::linearBlendSkinning()
{
/*
    if (skinned) {
        std::vector<glm::vec4> newPositions;
        for (int i = 0; i < vertices.size(); i++) {
            //each transformation slot will emit a signal to myGL that will call this function on the current mesh
            //get the bind matrix
            // get new transformation of joint

            glm::vec4 newPos = glm::vec4(0.0f);
            for ( auto it = vertices[i].jointInfluences.begin(); it != vertices[i].jointInfluences.end(); ++it ) {
                glm::vec4 posToInterpolate = it->second * ((it->first->getOverallTransformation() * it->first->getBindMatrix()) * glm::vec4(vertices[i].position, 1.0f));
                newPos = newPos + posToInterpolate;
            }
            newPositions.push_back(newPos);
        }

        std::vector<GLuint> idx;
        std::vector<glm::vec4> pos;
        std::vector<glm::vec4> nor;

        GLuint index = 0;
        for(Face f : faces)
        {
            glm::vec3 p0, p1, p2;
            p0 = glm::vec3(newPositions[f.vertices[0]]);
            p1 = glm::vec3(newPositions[f.vertices[1]]);
            p2 = glm::vec3(newPositions[f.vertices[2]]);

            //finding normal for each face
            glm::vec3 e1 = p0 - p1;
            glm::vec3 e2 = p1 - p2;
            glm::vec4 n = glm::vec4(glm::cross(e1, e2), 0.0f);

            for(int i = 0; i < 3; i++)
            {
                idx.push_back(index++);
                pos.push_back(newPositions[f.vertices[i]]);
                nor.push_back(n);
            }
        }

        count = idx.size();

        this->color = glm::vec4(1.0f, 0.5f, 0.75f, 1.0f);

        bufIdx.create();
        bufIdx.bind();
        bufIdx.setUsagePattern(QOpenGLBuffer::StaticDraw);
        bufIdx.allocate(idx.data(), idx.size() * sizeof(GLuint));

        bufPos.create();
        bufPos.bind();
        bufPos.setUsagePattern(QOpenGLBuffer::StaticDraw);
        bufPos.allocate(pos.data(), pos.size() * sizeof(glm::vec4));

        bufNor.create();
        bufNor.bind();
        bufNor.setUsagePattern(QOpenGLBuffer::StaticDraw);
        bufNor.allocate(nor.data(), nor.size() * sizeof(glm::vec4));
    }
*/
}

