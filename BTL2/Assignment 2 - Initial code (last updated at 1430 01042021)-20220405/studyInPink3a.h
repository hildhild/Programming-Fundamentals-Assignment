/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

class Point {
private:
    int x;
    int y;
public:
    Point(int x=0, int y=0);
    string toString() const;

    int distanceTo(const Point & otherPoint) const;
};
Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}
string Point::toString() const{
    string str = "";
    str += "<Point[";
    str += std::to_string(x);
    str += ",";
    str += std::to_string(y);
    str += "]>";
    return str;
}
int Point::distanceTo(const Point &otherPoint) const{
    return ceil(sqrt(pow(x-otherPoint.x,2)+ pow(y - otherPoint.y, 2)));
}

class Node {
private:
    Point point;
    Node * next;

    friend class Path;

public:
    Node(const Point & point=Point(), Node * next=NULL);
    string toString() const;
};
Node::Node(const Point& point, Node* next) {
    this->point = point;
    this->next = next;
}
string Node::toString() const {
    string str = "";
    str += "<Node[";
    str += point.toString();
    str += "]>";
    return str;
}

class Path {
private:
    Node * head;
    Node * tail;
    int count;
    int length;

public:
    Path();
    ~Path();

    void addPoint(int x, int y);
    string toString() const;
    Point getLastPoint() const;
    int lengthpath() const;
};
Path::Path() {
    head = NULL;
    tail = NULL;
    count = 0;
    length = -1;
}
Path::~Path() {
    while (count > 0) {
        Node*cur = this->head;
        this->head = this->head->next;
        delete cur;
        this->count--;
    }
    this->tail = NULL;
}
void Path::addPoint(int x, int y) {
    Node* newnode = new Node();
    newnode->point = Point(x, y);
    if (this->head != NULL && this->tail != NULL) {
        this->tail->next = newnode;
        this->tail = newnode;
        this->count++;
    }
    else {
        this->head = newnode;
        this->tail = newnode;
        this->count++;

    }
    if (this->count == 0) {
        this->length = -1;
    }
    else if (this->count == 1) {
        this->length = 0;
    }
    else {
        this->length = 0;
        Node* node = this->head;
        while (node != this->tail) {
            this->length += ceil(node->point.distanceTo(node->next->point));
            node = node->next;
        }
    }
}
string Path::toString() const {
    string str;
    str += "<Path[count:";
    str += std::to_string(this->count);
    str += ",length:";
    str += std::to_string(this->length);
    str += ",[";
    Node* node = this->head;
    while (node != this->tail) {
        str += node->toString();
        str += ",";
        node = node->next;
    }
    if (this->tail != NULL) {
        str += this->tail->toString();
    }
    str += "]]>";
    return str;
}
Point Path::getLastPoint() const {
    return tail->point;
}
int Path::lengthpath() const {
    return length;
}

class Character {
private:
    string name;
    Path * path;

public:
    Character(const string & name="");
    ~Character();

    string getName() const;
    void setName(const string & name);

    void moveToPoint(int x, int y);
    string toString() const;
    friend bool rescueSherlock(
        const Character& chMurderer,
        const Character& chWatson,
        int maxLength,
        int maxDistance,
        int& outDistance
    ) ;
};
Character::Character(const string& name) {
    this->name = name;
    Path* path1=new Path();
    this->path = path1;
}
Character::~Character() {
    this->path->~Path();
}
string Character::getName() const {
    return this->name;
}
void Character::setName(const string& name) {
    this->name = name;
}
void Character::moveToPoint(int x, int y) {
    path->addPoint(x, y);
}
string Character::toString() const {
    string str;
    str += "<Character[name:";
    str += this->name;
    str += ",path:";
    str += path->toString();
    str += "]>";
    return str;
}

bool rescueSherlock(
        const Character & chMurderer,
        const Character & chWatson,
        int maxLength,
        int maxDistance,
        int & outDistance
        ) {
    int l1 = chWatson.path->lengthpath();
    int l2 = chMurderer.path->lengthpath();
    if (l1 - l2 <= maxLength) {
        Point p1 = chWatson.path->getLastPoint();
        Point p2 = chMurderer.path->getLastPoint();
        outDistance= p1.distanceTo(p2);
        if (outDistance <= maxDistance) return 1;
        return 0;
    }
    else {
        outDistance = -1;
        return 0;
    }
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */