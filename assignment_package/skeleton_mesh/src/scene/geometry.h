#pragma once
#include <shaderprogram.h>

class Geometry : public ShaderProgram::Drawable
{
protected:
    int count;
    QOpenGLBuffer bufIdx;
    QOpenGLBuffer bufPos;
    QOpenGLBuffer bufNor;
    QOpenGLBuffer bufCol;
    QOpenGLBuffer bufID;
    QOpenGLBuffer bufWeights;
public:
    Geometry();
    virtual ~Geometry(){destroy();}

    virtual void create() = 0;
    void destroy();

    virtual GLenum drawMode();
    virtual int elemCount();
    virtual bool bindIdx();
    virtual bool bindPos();
    virtual bool bindNor();
    virtual bool bindCol();
    virtual bool bindID();
    virtual bool bindWeights();
};
