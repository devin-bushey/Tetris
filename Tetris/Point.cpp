#include <iostream>
#include <sstream>
#include "Point.h"


Point::Point()
{
	setXY(0, 0);
}

Point::Point(int x, int y) : Point()
{
	setXY(x, y);
}

int Point::getX() const
{
	return x;
}

int Point::getY() const 
{
	return y;
}

void Point::setX(int x) 
{
	this->x = x;
}

void Point::setY(int y) 
{
	this->y = y;
}

void Point::setXY(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Point::swapXY() 
{
	int tempX = x;
	x = y;
	y = tempX;
}

void Point::multiplyX(int factor) 
{
	x = x * factor;
}

void Point::multiplyY(int factor) 
{
	y = y * factor;
}

std::string Point::toString() const 
{
	std::stringstream ss;
	ss << "[" << x << "," << y << "]";
	return ss.str();
}