#include "shaderprogram.h"


void ShaderProgram::create(const char *vertfile, const char *fragfile)
{
    prog.addShaderFromSourceFile(QOpenGLShader::Vertex  , vertfile);
    prog.addShaderFromSourceFile(QOpenGLShader::Fragment, fragfile);
    prog.link();

    attrPos = prog.attributeLocation("vs_Pos");
    attrNor = prog.attributeLocation("vs_Nor");
    attrCol = prog.attributeLocation("vs_Col");
    attrInfluencers = prog.attributeLocation("influencer_IDs");
    attrWeights = prog.attributeLocation("influencer_weights");
    unifModel      = prog.uniformLocation("u_Model");
    unifModelInvTr = prog.uniformLocation("u_ModelInvTr");
    unifBindMatrices = prog.uniformLocation("bind_matrices");
    unifJointTrans = prog.uniformLocation("joint_transforms");
    unifViewProj   = prog.uniformLocation("u_ViewProj");
    unifColor      = prog.uniformLocation("u_Color");
    unifEye      = prog.uniformLocation("u_Eye");
}

void ShaderProgram::setModelMatrix(const glm::mat4 &model)
{
    prog.bind();

    if (unifModel != -1) {
        QMatrix4x4 test = la::to_qmat(model);
        prog.setUniformValue(unifModel, la::to_qmat(model));
    }

    if (unifModelInvTr != -1) {
        glm::mat4 modelinvtr = glm::inverse(glm::transpose(model));
        prog.setUniformValue(unifModelInvTr, la::to_qmat(modelinvtr));
    }
}
/*
void ShaderProgram::setBindMatrices(Skeleton &s)
{
    glm::mat4 bindmatrices[100];

    for (int i = 0; i < s.getChildrenCount(); i++) {
        transmatrices[i] = s.getChildAt(i)->getBindMatrix();
    }

    prog.bind();

    if (unifBindMatrices!= -1) {
        const glm::mat4 finalbinds[100] = bindmatrices;
        prog.setUniformValue(unifBindMatrices, finalbinds);
    }
}

void ShaderProgram::setTransMatrices(Skeleton &s)
{
    glm::mat4 transmatrices[100];

    for (int i = 0; i < s.getChildrenCount(); i++) {
        transmatrices[i] = s.getChildAt(i)->getOverallTransformation();
    }

    prog.bind();

    if (unifJointTrans!= -1) {
        const glm::mat4 finaltrans = transmatrices;
        prog.setUniformValue(unifJointTrans, finaltrans);
    }
}*/

void ShaderProgram::setBindMatrices(const QMatrix4x4 *bindmatrices)
{
    prog.bind();

    if (unifBindMatrices!= -1) {
        //const QMatrix4x4 &s = (bindmatrices[0]);
        prog.setUniformValueArray(unifBindMatrices, bindmatrices, 100);
    }
}

void ShaderProgram::setTransMatrices(const QMatrix4x4 *transmatrices)
{
    prog.bind();

    if (unifJointTrans!= -1) {
        //const QMatrix4x4 &s = (transmatrices[0]);
        prog.setUniformValueArray(unifJointTrans, transmatrices, 100);
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


    if (attrCol != -1 && d.bindCol()) {
        prog.enableAttributeArray(attrCol);
        f.glVertexAttribPointer(attrCol, 4, GL_FLOAT, false, 0, NULL);
    }

    if (attrInfluencers != -1 && d.bindID()) {
        prog.enableAttributeArray(attrInfluencers);
        f.glVertexAttribPointer(attrInfluencers, 4, GL_FLOAT, false, 0, NULL);
    }

    if (attrWeights != -1 && d.bindWeights()) {
        prog.enableAttributeArray(attrWeights);
        f.glVertexAttribPointer(attrWeights, 4, GL_FLOAT, false, 0, NULL);
    }
    // Bind the index buffer and then draw shapes from it.
    // This invokes the shader program, which accesses the vertex buffers.
    d.bindIdx();
    f.glDrawElements(d.drawMode(), d.elemCount(), GL_UNSIGNED_INT, 0);

    if (attrPos != -1) prog.disableAttributeArray(attrPos);
    if (attrNor != -1) prog.disableAttributeArray(attrNor);
    if (attrCol != -1) prog.disableAttributeArray(attrCol);
    if (attrInfluencers != -1) prog.disableAttributeArray(attrNor);
    if (attrWeights != -1) prog.disableAttributeArray(attrCol);

    f.printGLErrorLog();
}

void ShaderProgram::Drawable::setColor(const glm::vec4& c){
    color = c;
}

glm::vec4 ShaderProgram::Drawable::getColor(){
    return color;
}
