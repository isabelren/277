#include "mytreewidget.h"
#include <la.h>
#include <iostream>
#include <QTextStream>

MyTreeWidget::MyTreeWidget(QWidget* parent) : QTreeWidget(parent)
{
    currentTrans = 0;
}

MyTreeWidget::~MyTreeWidget()
{

}

//adds new root node
void MyTreeWidget::slot_newRootNode(QTreeWidgetItem* n)
{
    this->takeTopLevelItem(0);
    QTreeWidget::addTopLevelItem(n);
}

void MyTreeWidget::slot_changeCurrentJoint()
{
    Joint* j = (Joint*)(currentItem());

    emit sig_xRot((double)j->getEulers()[0]);
    emit sig_yRot((double)j->getEulers()[1]);
    emit sig_zRot((double)j->getEulers()[2]);

    emit sig_xTrans(j->getTX());
    emit sig_yTrans(j->getTY());
    emit sig_zTrans(j->getTZ());

    emit sig_changeCurrent(j);

}

void MyTreeWidget::slot_xAdd() {
    Joint* j = (Joint*)(currentItem());

    if (j == nullptr) {
        return;
    }
    glm::quat rot = glm::angleAxis(5.0f, glm::vec3(1, 0, 0));
    j->concatRotation(rot);
    emit sig_xRot((double)(j->getEulers()[0]));
    emit sig_moveMesh();
    emit sig_update();

}

void MyTreeWidget::slot_xSub()
{
    Joint* j = (Joint*)(currentItem());
    if (j == nullptr) {
        return;
    }
    glm::quat rot = glm::angleAxis(-5.0f, glm::vec3(1, 0, 0));
    j->concatRotation(rot);
    emit sig_xRot((double)(j->getEulers()[0]));
    emit sig_moveMesh();
    emit sig_update();
}

void MyTreeWidget::slot_yAdd()
{
    Joint* j = (Joint*)(currentItem());
    if (j == nullptr) {
        return;
    }
    glm::quat rot = glm::angleAxis(5.0f, glm::vec3(0, 1, 0));
    j->concatRotation(rot);
    emit sig_xRot((double)(j->getEulers()[0]));
    emit sig_moveMesh();
    emit sig_update();
}

void MyTreeWidget::slot_ySub()
{
    Joint* j = (Joint*)(currentItem());
    if (j == nullptr) {
        return;
    }
    glm::quat rot = glm::angleAxis(-5.0f, glm::vec3(0, 1, 0));
    j->concatRotation(rot);
    emit sig_xRot((double)(j->getEulers()[0]));
    emit sig_moveMesh();
    emit sig_update();
}

void MyTreeWidget::slot_zAdd()
{
    Joint* j = (Joint*)(currentItem());
    if (j == nullptr) {
        return;
    }
    glm::quat rot = glm::angleAxis(5.0f, glm::vec3(0, 0, 1));
    j->concatRotation(rot);
    emit sig_xRot((double)(j->getEulers()[0]));
    emit sig_moveMesh();
    emit sig_update();
}

void MyTreeWidget::slot_zSub()
{
    Joint* j = (Joint*)(currentItem());
    if (j == nullptr) {
        return;
    }
    glm::quat rot = glm::angleAxis(-5.0f, glm::vec3(0, 0, 1));
    j->concatRotation(rot);
    emit sig_xRot((double)(j->getEulers()[0]));
    emit sig_moveMesh();
    emit sig_update();
}

void MyTreeWidget::slot_changeXTrans(double x)
{
    Joint* j = (Joint*)(currentItem());
    if (j == nullptr) {
        return;
    }
    j->setTransformation((float)x, j->getTY(), j->getTZ());
    emit sig_xTrans(j->getTX());
    emit sig_moveMesh();
    emit sig_update();
}

void MyTreeWidget::slot_changeYTrans(double x)
{
    Joint* j = (Joint*)(currentItem());
    if (j == nullptr) {
        return;
    }
    j->setTransformation(j->getTX(),(float)x, j->getTZ());
    emit sig_yTrans(j->getTY());
    emit sig_moveMesh();
    emit sig_update();
}

void MyTreeWidget::slot_changeZTrans(double x){
    Joint* j = (Joint*)(currentItem());
    if (j == nullptr) {
        return;
    }
    j->setTransformation(j->getTX(),j->getTY(), (float)x);
    emit sig_zTrans(j->getTZ());
    emit sig_moveMesh();
    emit sig_update();
}
