#ifndef CAMERA_H
#define CAMERA_H
//^^ what does this do vv?
#pragma once

//is camera geometry? no bc is not being rendered?
//Do i need to include QOpenGLContext?
#include <vector>
#include "shaderprogram.h"
#include <la.h>
#include <QOpenGLContext>


class Camera
{
private:
    float theta, phi, zoom, fovy, width, height, near_clip, far_clip;

public:
    Camera();

    //Are there style guidelines for long lines? vv
    Camera(float theta, float phi, float zoom, float fovy, float width, float height, float near_clip, float far_clip);
    ~Camera();

    glm::mat4 getProjMat();
    glm::mat4 getViewMat();
    float getAspectRatio();
    void setTheta(float x);
    float getTheta();
    void setPhi(float x);
    float getPhi();
    void setZoom(float x);
    float getZoom();
    void setFovy(float x);
    float getFovy();
    void setWidth(float x);
     float getWidth();
    void setHeight(float x);
     float getHeight();
    void setNearClip(float x);
    float getNearClip();
    void setFarClip(float x);
    float getFarClip();


};

#endif // CAMERA_H
