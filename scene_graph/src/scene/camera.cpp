#include "camera.h"
#include <math.h>

Camera::Camera()
{
    theta = phi = zoom = 0;
    zoom = 0;
    fovy = 45;
    width = 10;
    height = 10;
    near_clip = 0.1;
    far_clip = 1000;
}

Camera::Camera(float theta, float phi, float zoom, float fovy, float width, float height, float near_clip, float far_clip)
{
    this->theta = theta; this->phi = phi; this->zoom = zoom;
    this->fovy = fovy; this->width = width; this->height = height;
    this->near_clip = near_clip; this->far_clip = far_clip;
}

Camera::~Camera()
{
//what to put here?
}

glm::mat4 Camera::getProjMat() {
    return glm::perspective(this->fovy, this->getAspectRatio(), this->near_clip, this->far_clip);
}

glm::mat4 Camera::getViewMat()
{
    //CONVERT BETWEEN RADIANS AND DEGREES
    float eyeX = this->zoom * sin(this->theta);
    float eyeY = this->zoom * cos(this->theta) * cos(this->phi);
    float eyeZ = this->zoom * cos(this->theta) * sin(this->phi);

    //vec3 or vec4??
    glm::mat4 rotationToCenter = glm::rotate(glm::mat4(1.0f), this->theta, glm::vec3(0, 1, 0)) * glm::rotate(glm::mat4(1.0f), this->phi, glm::vec3(1, 0, 0));

    glm::vec4 center4 = rotationToCenter * glm::vec4(1, 0, 0, 1);
    glm::vec3 center = glm::vec3(center4[0]/center4[3], center4[1]/center4[3],center4[2]/center4[3]);
    glm::vec3 right = glm::normalize(glm::cross(center, glm::vec3(0,1,0)));
    glm::vec3 up = glm::normalize(glm::cross(right, center));

    //eye, center, up
    return glm::lookAt(glm::vec3(eyeX,eyeY,eyeZ), center, up);
}

float Camera::getAspectRatio()
{
    float aspectRatio = this->width / this->height;
    return aspectRatio;
}

void Camera::setTheta(float x)
{
    this->theta = x;
}

float Camera::getTheta()
{
    return this->theta;
}

void Camera::setPhi(float x)
{
    this->phi = x;
}

float Camera::getPhi()
{
    return this->phi;
}

void Camera::setZoom(float x)
{
    this->zoom = x;
}

float Camera::getZoom()
{
    return this->zoom;
}


void Camera::setFovy(float x)
{
    this->fovy = x;
}

float Camera::getFovy()
{
    return this->fovy;
}

void Camera::setWidth(float x)
{
    this->width = x;
}
float Camera::getWidth()
{
    return this->width;
}

void Camera::setHeight(float x)
{
    this->height = x;
}

float Camera::getHeight()
{
    return this->height;
}
void Camera::setNearClip(float x)
{
    this->near_clip = x;
}

float Camera::getNearClip()
{
    return this->near_clip;
}

void Camera::setFarClip(float x)
{
    this->far_clip = x;
}

float Camera::getFarClip()
{
    return this->far_clip;
}
