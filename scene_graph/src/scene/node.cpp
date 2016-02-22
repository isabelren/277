#include "node.h"

Node::Node()
{
    tx = ty = tz = rx = ry = rz = 0;
    sx = sy = sz = 1;
    geom_color = glm::vec4(1,1,1,1);

    parent = NULL;
    geometry = NULL;
    name = "untitled";
}

Node::Node(QString name, float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz){
    this->tx = tx; this->ty = ty; this->tz = tz;
    this->rx = rx; this->ry = ry; this->rz = rz;
    this->sx = sx; this->sy = sy; this->sz = sz;
    this->name = name;
    geom_color = glm::vec4(1,1,1,1);

    QTreeWidgetItem::setText(0, name);
    parent = NULL;
    geometry = NULL;
}

Node::~Node()
{
    while(children.size() > 0){
        delete children[0];
        children.erase(children.begin());
    }
}

int Node::childCount(){
    return children.size();
}

Node* Node::childAt(int idx){
    return children[idx];
}

void Node::addChild(QTreeWidgetItem* child){
    QTreeWidgetItem::addChild(child);
    Node* c = (Node*)child;
    children.push_back(c);
    c->setParent(this);
}

//removes child from children vector
void Node::removeSingleChild(QTreeWidgetItem* child)
{
    Node* n = (Node*)child;

    //remove current as a parent
    n->setParent(nullptr);

    //remove child from vector
    //children.erase(child);
    children.erase(std::remove(children.begin(), children.end(), child), children.end());

    //remove child from QTreeWidgeetItem
    QTreeWidgetItem::removeChild(child);

}

//takes all children of the child in question
void Node::takeChildren(QTreeWidgetItem* child)
{
    for (int i =0; i < childCount(); i++) {
        (((Node*)child)->childAt(i))->setParent(this);
        addChild(((Node*)child)->childAt(i));
    }
}

void Node::setParent(Node* n){
    parent = n;
}

void Node::setGeometry(ShaderProgram::Drawable* g){
    geometry = g;
}

ShaderProgram::Drawable* Node::getGeometry(){
    return geometry;
}

void Node::setGeomColor(const glm::vec4& c){
    geom_color = c;
}

const glm::vec4& Node::getGeometryColor() const {
    return geom_color;
}

void Node::setTranslation(float x, float y, float z)
{
    this->tx = x;
    this->ty = y;
    this->tz = z;
}

void Node::setRotation(float x, float y, float z)
{
    this->rx = x;
    this->ry = y;
    this->rz = z;
}

void Node::setScale(float x, float y, float z)
{
    this->sx = x;
    this->sy = y;
    this->sz = z;
}

void Node::setName(QString s)
{
    this->name = s;
}

Node* Node::getParent() {

    return parent;
}

double Node::getTX()
{
    return (double)this->tx;
}
double Node::getTY()
{
    return (double)this->ty;
}
double Node::getTZ()
{
    return (double)this->tz;
}

double Node::getRX()
{
    return (double)this->rx;
}
double Node::getRY()
{
    return (double)this->ry;
}
double Node::getRZ()
{
    return (double)this->rz;
}

double Node::getSX()
{
    return (double)this->sx;
}
double Node::getSY()
{
    return (double)this->sy;
}
double Node::getSZ()
{
    return (double)this->sz;
}


glm::mat4 Node::getTransMat(){
    glm::mat4 T = glm::translate(glm::mat4(1.0f), glm::vec3(tx, ty, tz));
    glm::mat4 Rx = glm::rotate(glm::mat4(1.0f), rx, glm::vec3(1, 0, 0));
    glm::mat4 Ry = glm::rotate(glm::mat4(1.0f), ry, glm::vec3(0, 1, 0));
    glm::mat4 Rz = glm::rotate(glm::mat4(1.0f), rz, glm::vec3(0, 0, 1));
    glm::mat4 S = glm::scale(glm::mat4(1.0f), glm::vec3(sx, sy, sz));

    return T * Rx * Ry * Rz * S;
}
