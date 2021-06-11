#include "Box.h"


void Box::setfirstX(int x)
{
    this->firstX = x;
}

void Box::setfirstY(int y)
{
    this->firstY = y;
}

int Box::getfirstX()
{
    return firstX;
}

int Box::getfirstY()
{
    return firstY;
}

void Box::setendX(int x)
{
    this->endX = x;
}

void Box::setendY(int y)
{
    this->endY = y;
}

int Box::getendX()
{
    return endX;
}

int Box::getendY()
{
    return endY;
}

int Box::getArea()
{
    return this->area;
}

void Box::setArea(int area)
{
    this->area = area;
}