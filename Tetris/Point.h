#pragma once
#include <iostream>

class Point
{
private:
	int x;
	int y;

public:
	// FRIENDS
	friend class TestSuite;// (allows TestSuite access to private members for testing)

	Point();

	Point(int x, int y);

	int getX() const;

	int getY() const;

	void setX(int x);

	void setY(int y);

	void setXY(int x, int y);

	// swap x and y
	void swapXY();

	// multiply x by some factor
	void multiplyX(int factor);

	// multiply y by some factor
	void multiplyY(int factor);

	// return a string in the form "[x,y]" to represent the state of the Point instance
	// (for debugging) You could use stringstream if you want to try a forming a string in
	// the same way you use cout http://stev.org/post/cstringstreamexample for an example
	std::string toString() const;
};
