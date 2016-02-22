#include "cube.h"
#include<la.h>
#include <iostream>

static const int CUBE_IDX_COUNT = 36;
static const int CUBE_VERT_COUNT = 24;

Cube::Cube() : Geometry()
{}

//These are functions that are only defined in this cpp file. They're used for organizational purposes
//when filling the arrays used to hold the vertex and index data.
void createCubeVertexPositions(glm::vec4 (&cube_vert_pos)[CUBE_VERT_COUNT]){
    float p = 0.5f;
    float n = -0.5f;
    //Create four squares of vertices

    //Store negative x face
    cube_vert_pos[0] = glm::vec4(n, n, p, 1);
    cube_vert_pos[1] = glm::vec4(n, p, p, 1);
    cube_vert_pos[2] = glm::vec4(n, p, n, 1);
    cube_vert_pos[3] = glm::vec4(n, n, n, 1);

    //Store positive x face
    cube_vert_pos[4] = glm::vec4(p, n, p, 1);
    cube_vert_pos[5] = glm::vec4(p, p, p, 1);
    cube_vert_pos[6] = glm::vec4(p, p, n, 1);
    cube_vert_pos[7] = glm::vec4(p, n, n, 1);

    //Store negative y face
    cube_vert_pos[8] = glm::vec4(p, n, n, 1);
    cube_vert_pos[9] = glm::vec4(p, n, p, 1);
    cube_vert_pos[10] = glm::vec4(n, n, p, 1);
    cube_vert_pos[11] = glm::vec4(n, n, n, 1);

    //Store positive y face
    cube_vert_pos[12] = glm::vec4(p, p, n, 1);
    cube_vert_pos[13] = glm::vec4(p, p, p, 1);
    cube_vert_pos[14] = glm::vec4(n, p, p, 1);
    cube_vert_pos[15] = glm::vec4(n, p, n, 1);

    //Store negative z face
    cube_vert_pos[16] = glm::vec4(n, p, n, 1);
    cube_vert_pos[17] = glm::vec4(p, p, n, 1);
    cube_vert_pos[18] = glm::vec4(p, n, n, 1);
    cube_vert_pos[19] = glm::vec4(n, n, n, 1);

    //Store positive z face
    cube_vert_pos[20] = glm::vec4(n, p, p, 1);
    cube_vert_pos[21] = glm::vec4(p, p, p, 1);
    cube_vert_pos[22] = glm::vec4(p, n, p, 1);
    cube_vert_pos[23] = glm::vec4(n, n, p, 1);


}

//change in surface normal only affects lighting
void createCubeVertexNormals(glm::vec4 (&cube_vert_nor)[CUBE_VERT_COUNT]){

    //Store -x normals (IDX 0 - 3)
    for (int i = 0; i < 4; i++){
        cube_vert_nor[i] =  glm::vec4(-1,0,0,0);
    }

    //Store +x normals (IDX 4-7)
    for (int i = 4; i < 8; i++){
        cube_vert_nor[i] =  glm::vec4(1,0,0,0);
    }

    //Store -y normals (IDX 8 - 11)
    for (int i = 8; i < 12; i++){
        cube_vert_nor[i] =  glm::vec4(0,-1,0,0);
    }

    //Store +y normals (IDX 12 - 15)
    for (int i = 12; i < 16; i++){
        cube_vert_nor[i] =  glm::vec4(0,1,0,0);
    }
    //Store -z normals (IDX 16 - 19)
    for (int i = 16; i < 20; i++){
        cube_vert_nor[i] =  glm::vec4(0,0,0,-1);
    }

    //Store +z normals (IDX 20 - 23)
    for (int i = 20; i < 24; i++){
        cube_vert_nor[i] =  glm::vec4(0,0,0,1);
    }
}

//All triangles are coplanar
void createCubeIndices(GLuint (&cube_idx)[CUBE_IDX_COUNT]){
    //Build indices for each face (2 tris each)
    for(int i = 0; i < 6; i++){
        cube_idx[i*6] = i*4;
        cube_idx[i*6+1] = i*4 + 2;
        cube_idx[i*6+2] = i*4 + 3;
        cube_idx[i*6+3] = i*4;
        cube_idx[i*6+4] = i*4 + 2;
        cube_idx[i*6+5] = i*4 + 1;
    }
}

void Cube::create()
{
    GLuint cube_idx[CUBE_IDX_COUNT];
    glm::vec4 cube_vert_pos[CUBE_VERT_COUNT];
    glm::vec4 cube_vert_nor[CUBE_VERT_COUNT];

    createCubeVertexPositions(cube_vert_pos);
    createCubeVertexNormals(cube_vert_nor);
    createCubeIndices(cube_idx);

    count = CUBE_IDX_COUNT;

    //QOpenGLBuffer Class
    bufIdx.create();
    bufIdx.bind();
    bufIdx.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufIdx.allocate(cube_idx, CUBE_IDX_COUNT * sizeof(GLuint));

    //sending array of information to graphics card
    bufPos.create();
    bufPos.bind();
    bufPos.setUsagePattern(QOpenGLBuffer::StaticDraw);
    //CUBE_VERT_COUNT is malloc-ing; putting cyl_vert_pos in
    bufPos.allocate(cube_vert_pos,CUBE_VERT_COUNT * sizeof(glm::vec4));

    bufNor.create();
    bufNor.bind();
    bufNor.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufNor.allocate(cube_vert_nor, CUBE_VERT_COUNT * sizeof(glm::vec4));
}
