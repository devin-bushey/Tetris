#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

#include "Tetromino.h"
#include "Point.h"


Tetromino::Tetromino()
{
	Tetromino::setShape(Tetromino::TetShape::O);

}
Tetromino::TetColor Tetromino::getColor() const {

	return color;
}

Tetromino::TetShape Tetromino::getShape() const {

	return shape;
}

void Tetromino::setShape(TetShape shape) {

	blockLocs.clear();
	this->shape = shape;
	switch (shape) {

	case Tetromino::TetShape::O:
		blockLocs = { Point(0, 0), Point(1, 1), Point(0,1), Point(1,0) };
		color = TetColor::YELLOW;
		break;

	case Tetromino::TetShape::I:
		blockLocs = { Point(0, 0), Point(0, -1), Point(0,1), Point(0,2) };
		color = TetColor::BLUE_LIGHT;
		break;

	case Tetromino::TetShape::S:
		blockLocs = { Point(0, 0), Point(-1, 0), Point(0,1), Point(1,1) };
		color = TetColor::RED;
		break;

	case Tetromino::TetShape::Z:
		blockLocs = { Point(0, 0), Point(-1, 1), Point(0,1), Point(1,0) };
		color = TetColor::GREEN;
		break;

	case Tetromino::TetShape::L:
		blockLocs = { Point(0, 0), Point(0, 1), Point(0,-1), Point(1, -1) };
		color = TetColor::ORANGE;
		break;

	case Tetromino::TetShape::J:
		blockLocs = { Point(0, 0), Point(0, 1), Point(0,-1), Point(-1, -1) };
		color = TetColor::BLUE_DARK;
		break;

	case Tetromino::TetShape::T:
		blockLocs = { Point(0, 0), Point(-1, 0), Point(1, 0), Point(0,-1) };
		color = TetColor::PURPLE;
		break;
	
	}

}


void Tetromino::rotateClockwise() {

	for (Point &pt : blockLocs) {
		pt.swapXY();
		pt.multiplyY(-1);
	}

}

void Tetromino::printToConsole() const {

	// Y axis
	for (int col = 3; col > -4; col--)
	{
		// X axis
		for (int row = -3; row < 4; row++)
		{

			bool found = false;

			for (Point pt : blockLocs) {

				if (pt.getX() == row && pt.getY() == col) {
					found = true;
					//std::cout << pt.toString();
				}
			}

			if (found) {
				std::cout << "x";
			}
			else {
				std::cout << ".";
			}
		}
		std::cout << "\n";
	}
}

Tetromino::TetShape Tetromino::getRandomShape() {
	int shape = rand() % (int)TetShape::COUNT;
	return (Tetromino::TetShape)shape;
}