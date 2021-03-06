#include "shaderprogram.h"


void ShaderProgram::create(const char *vertfile, const char *fragfile)
{
    prog.addShaderFromSourceFile(QOpenGLShader::Vertex  , vertfile);
    prog.addShaderFromSourceFile(QOpenGLShader::Fragment, fragfile);
    prog.link();

    //
    attrPos = prog.attributeLocation("vs_Pos");
    attrNor = prog.attributeLocation("vs_Nor");
    attrCol = prog.attributeLocation("vs_Col");

    unifModel      = prog.uniformLocation("u_Model");
    unifModelInvTr = prog.uniformLocation("u_ModelInvTr");
    unifViewProj   = prog.uniformLocation("u_ViewProj");
    unifColor      = prog.uniformLocation("u_Color");
}

void ShaderProgram::setModelMatrix(const glm::mat4 &model)
{
    prog.bind();

    if (unifModel != -1) {
        QMatrix4x4 test = la::to_qmat(model);
        //pointer to unifModel, sent data to graphics card
        prog.setUniformValue(unifModel, la::to_qmat(model));
    }

    if (unifModelInvTr != -1) {
        glm::mat4 modelinvtr = glm::transpose(model);
        modelinvtr = glm::inverse(model);
        prog.setUniformValue(unifModelInvTr, la::to_qmat(modelinvtr));
    }
}

//This function, as its name implies, uses the passed in GL widget
void ShaderProgram::draw(GLWidget277 &f, Drawable &d)
{
    prog.bind();

    //Send the Drawable's color to the shader
    if(unifColor != -1){
        prog.setUniformValue(unifColor, la::to_qvec(d.getColor()));
    }

    // Each of the following blocks checks that:
    //   * This shader has this attribute, and
    //   * This Drawable has a vertex buffer for this attribute.
    // If so, it binds the appropriate buffers to each attribute.

    if (attrPos != -1 && d.bindPos()) {
        prog.enableAttributeArray(attrPos);
        f.glVertexAttribPointer(attrPos, 4, GL_FLOAT, false, 0, NULL);
    }

    if (attrNor != -1 && d.bindNor()) {
        prog.enableAttributeArray(attrNor);
        f.glVertexAttribPointer(attrNor, 4, GL_FLOAT, false, 0, NULL);
    }

    // Bind the index buffer and then draw shapes from it.
    // This invokes the shader program, which accesses the vertex buffers.
    d.bindIdx();
    //vv Draws elements using all info passed in
    f.glDrawElements(d.drawMode(), d.elemCount(), GL_UNSIGNED_INT, 0);

    if (attrPos != -1) prog.disableAttributeArray(attrPos);
    if (attrNor != -1) prog.disableAttributeArray(attrNor);

    f.printGLErrorLog();
}

void ShaderProgram::Drawable::setColor(const glm::vec4& c){
    color = c;
}

glm::vec4 ShaderProgram::Drawable::getColor(){
    return color;
}
