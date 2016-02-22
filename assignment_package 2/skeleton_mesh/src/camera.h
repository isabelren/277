#pragma once
#include <la.h>

class Camera
{
public:
    Camera();
    float phi, theta, zoom, aspect;
    glm::vec3 eye, up;

    glm::mat4 viewProj();
    void recompute(float w, float h);
};
