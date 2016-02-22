#include <camera.h>

Camera::Camera() : phi(-45), theta(45), zoom(10), aspect(1.0f){}

glm::mat4 Camera::viewProj()
{
    return glm::perspective(45.0f, aspect, 0.01f, 100.0f) * glm::lookAt(eye, glm::vec3(0,0,0), up);
}


void Camera::recompute(float w, float h)
{
    aspect = w/h;
    eye = glm::vec3(glm::rotate(glm::mat4(1.0f), theta, glm::vec3(0,1,0)) * glm::rotate(glm::mat4(1.0f), phi, glm::vec3(1,0,0)) * glm::vec4(0,0,zoom,1));
    up = glm::vec3(glm::rotate(glm::mat4(1.0f), theta, glm::vec3(0,1,0)) * glm::rotate(glm::mat4(1.0f), phi, glm::vec3(1,0,0)) * glm::vec4(0,1,0,0));
}
