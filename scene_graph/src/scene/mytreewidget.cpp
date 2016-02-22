#include "mytreewidget.h"

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
    QTreeWidget::addTopLevelItem(n);
}

void MyTreeWidget::slot_changeTrans(int i) {
    currentTrans = i;
    emit sig_newTrans(currentTrans);
    //connect this signal with each of the text edits
}

void MyTreeWidget::slot_addChildNode(ShaderProgram::Drawable* shape) {
    Node* n = new Node();
    n->setGeometry(shape);

    if (currentItem() != 0) {
        ((Node*)currentItem())->addChild(n);
    }

}

void MyTreeWidget::slot_removeSingleChild()
{
    if (currentItem() != topLevelItem(0)) {
        Node* n = (Node*)currentItem();
        Node* parent = n->getParent();
        std::vector<Node*> newChildren;

        for (int i=0; i < n->childCount(); i++) {
            newChildren.push_back(n->childAt(i));
            parent->removeSingleChild(n);
            n->removeChild(n->childAt(i));
        }

        parent->removeSingleChild(n);
        parent->removeChild(n);

        QTreeWidget::setCurrentItem(parent);

        Node* newChild;
        for (int j = 0; j < newChildren.size(); j++) {
            newChild = newChildren[j];
            newChild->setParent((Node*)currentItem());
            ((Node*)currentItem())->addChild(newChild);
        }
    }
}

void MyTreeWidget::slot_removeAllChildren()
{
    if (currentItem() != topLevelItem(0)) {
        Node* n = (Node*)currentItem();
        Node* parent = n->getParent();

        parent->removeSingleChild(n);
        parent->removeChild(n); //removes from widget
    }


}

void MyTreeWidget::slot_rename(QString s)
{
    Node* c = (Node*)(currentItem());
    c->setName(s);
    currentItem()->setText(0, s);
}

void MyTreeWidget::slot_changeCurrentNode()
{
    Node* c = (Node*)(currentItem());
    switch (currentTrans)
    {
    case 0: //TRANSLATION
        emit sig_XTrans(c->getTX());
        emit sig_YTrans(c->getTY());
        emit sig_ZTrans(c->getTZ());
        break;
    case 1: //ROTATION
        emit sig_XTrans(c->getRX());
        emit sig_YTrans(c->getRY());
        emit sig_ZTrans(c->getRZ());
        break;
    case 2: //SCALE
        emit sig_XTrans(c->getSX());
        emit sig_YTrans(c->getSY());
        emit sig_ZTrans(c->getSZ());
        break;
    default:
        emit sig_XTrans(c->getTX());
        emit sig_YTrans(c->getTY());
        emit sig_ZTrans(c->getTZ());
        break;
    };

}

void MyTreeWidget::slot_changeXTrans(double x)
{
    Node* c = (Node*)(currentItem());
    switch (currentTrans)
    {
    case 0: //TRANSLATION
        c->setTranslation((float)x, c->getTY(), c->getTZ());
        break;
    case 1: //ROTATION
         c->setRotation((float)x, c->getRY(), c->getRZ());
        break;
    case 2: //SCALE
         c->setScale((float)x, c->getSY(), c->getSZ());
        break;
    }
    if (currentItem()!= nullptr) {
       emit sig_newTrans(currentTrans);
    }
}

void MyTreeWidget::slot_changeYTrans(double x)
{
    Node* c = (Node*)(currentItem());
    switch (currentTrans)
    {
    case 0: //TRANSLATION
        c->setTranslation(c->getTX(), (float)x, c->getTZ());
        break;
    case 1: //ROTATION
         c->setRotation(c->getRX(), (float)x, c->getRZ());
        break;
    case 2: //SCALE
         c->setScale(c->getSX(), (float)x, c->getSZ());
        break;
    }
    if (currentItem()!= nullptr) {
       emit sig_newTrans(currentTrans);
    }
}

void MyTreeWidget::slot_changeZTrans(double x)
{
    Node* c = (Node*)(currentItem());
    switch (currentTrans)
    {
    case 0: //TRANSLATION
        c->setTranslation(c->getTX(), c->getTY(), (float)x);
        break;
    case 1: //ROTATION
         c->setRotation(c->getRX(), c->getRY(), (float)x);
        break;
    case 2: //SCALE
         c->setScale(c->getSX(), c->getSY(), (float)x);
        break;
    }
    if (currentItem()!= nullptr) {
       emit sig_newTrans(currentTrans);
    }
}
