#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <vector>
#include <assert.h>
#include "Point.h"
#include "Tetromino.h"
#include "GridTetromino.h"


#ifdef GAMEBOARD_H
#include "Gameboard.h"
#endif

namespace Constants {
	const int BLOCK_COUNT{ 4 };
}

class TestSuite
{
public:
	static bool runTestSuite()
	{
		std::cout << "Running TestSuite ------------------------" << "\n";
		// run some sanity tests on our classes to ensure they're working as expected.
		TestSuite::testPointClass();
		TestSuite::testTetrominoClass();
		TestSuite::testGridTetrominoClass();

#ifdef GAMEBOARD_H
		TestSuite::testGameboardClass();
#endif

		std::cout << "TestSuite complete -----------------------" << "\n";
		return true;
	}

	static bool testGridTetrominoClass()
	{
		std::cout << " testGridTetrominoClass...";

		GridTetromino gt;

		// check if constructor sets gridLoc to 0,0
		assert(gt.getGridLoc().getX() == 0 && gt.getGridLoc().getY() == 0);

		// test setGridLoc(x,y)
		gt.setGridLoc(4, 5);
		assert(gt.getGridLoc().getX() == 4 && gt.getGridLoc().getY() == 5);

		// test setGridLoc(Point)
		gt.setGridLoc(Point(8, 9));
		assert(gt.getGridLoc().getX() == 8 && gt.getGridLoc().getY() == 9);

		// test move()
		gt.setGridLoc(1, 2);
		gt.move(5, 5);
		assert(gt.getGridLoc().getX() == 6 && gt.getGridLoc().getY() == 7);


		// test getBlockLocsMappedToGrid()
		gt.blockLocs = { Point(1,2) };
		gt.setGridLoc(5, 5);
		std::vector<Point> locs = gt.getBlockLocsMappedToGrid();
		assert(locs[0].getX() == 6 && locs[0].getY() == 7);


		std::cout << "passed!" << "\n";
		return true;
	}

	static bool testTetrominoClass()
	{
		std::cout << " testTetrominoClass...";

		Tetromino t;


		assert(t.getColor() == Tetromino::Tetromino::TetColor::RED ||
			t.getColor() == Tetromino::TetColor::ORANGE ||
			t.getColor() == Tetromino::TetColor::YELLOW ||
			t.getColor() == Tetromino::TetColor::GREEN ||
			t.getColor() == Tetromino::TetColor::BLUE_LIGHT ||
			t.getColor() == Tetromino::TetColor::BLUE_DARK ||
			t.getColor() == Tetromino::TetColor::PURPLE &&
			"default Tetromino not initialized to valid color.");

		assert(t.getShape() == Tetromino::TetShape::S ||
			t.getShape() == Tetromino::TetShape::Z ||
			t.getShape() == Tetromino::TetShape::L ||
			t.getShape() == Tetromino::TetShape::J ||
			t.getShape() == Tetromino::TetShape::O ||
			t.getShape() == Tetromino::TetShape::I ||
			t.getShape() == Tetromino::TetShape::T &&
			"default Tetromino not initialized to valid shape.");

		assert(t.blockLocs.size() == Constants::BLOCK_COUNT &&
			"default Tetromino has no blockLocs - likely because no default set in constructor");

		t.setShape(Tetromino::TetShape::S);
		assert(t.blockLocs.size() == Constants::BLOCK_COUNT && "Tetromino shape size should be 4");
		t.setShape(Tetromino::TetShape::Z);
		assert(t.blockLocs.size() == Constants::BLOCK_COUNT && "Tetromino shape size should be 4");
		t.setShape(Tetromino::TetShape::L);
		assert(t.blockLocs.size() == Constants::BLOCK_COUNT && "Tetromino shape size should be 4");
		t.setShape(Tetromino::TetShape::J);
		assert(t.blockLocs.size() == Constants::BLOCK_COUNT && "Tetromino shape size should be 4");
		t.setShape(Tetromino::TetShape::O);
		assert(t.blockLocs.size() == Constants::BLOCK_COUNT && "Tetromino shape size should be 4");
		t.setShape(Tetromino::TetShape::I);
		assert(t.blockLocs.size() == Constants::BLOCK_COUNT && "Tetromino shape size should be 4");
		t.setShape(Tetromino::TetShape::T);
		assert(t.blockLocs.size() == Constants::BLOCK_COUNT && "Tetromino shape size should be 4");


		// test the rotate functionality of a single block
		t.blockLocs.clear();
		t.blockLocs.push_back(Point(1, 2));
		t.rotateClockwise();
		assert(t.blockLocs[0].getX() == 2 && t.blockLocs[0].getY() == -1 && "Tetromino::rotateCW() failed");
		t.rotateClockwise();
		assert(t.blockLocs[0].getX() == -1 && t.blockLocs[0].getY() == -2 && "Tetromino::rotateCW() failed");
		t.rotateClockwise();
		assert(t.blockLocs[0].getX() == -2 && t.blockLocs[0].getY() == 1 && "Tetromino::rotateCW() failed");
		t.rotateClockwise();
		assert(t.blockLocs[0].getX() == 1 && t.blockLocs[0].getY() == 2 && "Tetromino::rotateCW() failed");

		std::cout << "passed!" << "\n";
		return true;
	}

	static bool testPointClass()
	{
		std::cout << " testPointClass()...";

		Point p;

		// test our initial values are 0,0
		assert(p.getX() == 0 && "Point ctor - x not initialized to 0");
		assert(p.getY() == 0 && "Point ctor - y not initialized to 0");

		// test setX()
		p.setX(1);
		assert(p.getX() == 1 && "Point::setX() failed");
		p.setX(-1);
		assert(p.getX() == -1 && "Point::setX() failed");

		// test setY()
		p.setY(2);
		assert(p.getY() == 2 && "Point::setY() failed");
		p.setY(-2);
		assert(p.getY() == -2 && "Point::setY() failed");

		// test setXY()
		p.setXY(3, 4);
		assert(p.getX() == 3 && p.getY() == 4 && "Point::setXY() failed");
		p.setXY(-3, -4);
		assert(p.getX() == -3 && p.getY() == -4 && "Point::setXY() failed");

		// test constructor with 2 params
		Point q(3, 4);
		assert(q.getX() == 3 && q.getY() == 4 && "Point::ctor failed to set default params");

		// test swapXY()
		q.swapXY();
		assert(q.getX() == 4 && q.getY() == 3 && "Point::swapXY() failed");

		// test multiplyX()
		q.multiplyX(-1);
		assert(q.getX() == -4 && "Point::multiplyX() failed");

		// test multiplyY()
		q.multiplyY(-1);
		assert(q.getY() == -3 && "Point::multiplyY() failed");

		// test copy constructor
		q.setXY(1, 2);
		Point r = q;
		assert(r.getX() == q.getX() && r.getY() == q.getY() && "Point copy ctor failed");
		r.setXY(3, 4);
		assert(r.getX() == 3 && r.getY() == 4
			&& q.getX() == 1 && q.getY() == 2 && "Point::setXY() failed");

		std::cout << "passed!" << "\n";
		return true;
	}


#ifdef GAMEBOARD_H
	static bool isGameboardEmpty(Gameboard &g)
	{
		for (int x = 0; x < Gameboard::MAX_X; x++) {
			for (int y = 0; y < Gameboard::MAX_Y; y++)
			{
				if (g.getContent(x, y) != Gameboard::EMPTY_BLOCK) { return false; }
			}
		}
		return true;
	}

	static bool testGameboardClass()
	{
		std::cout << " testGameboardClass... \n";
		Gameboard g;
		// test if grid content is initialized to empty blocks
		for (int x = 0; x < Gameboard::MAX_X; x++) {
			for (int y = 0; y < Gameboard::MAX_Y; y++) {
				assert(g.getContent(x, y) == Gameboard::EMPTY_BLOCK);
			}
		}

		// test setGridContent(x,y,content)
		g.setContent(0, 0, 1);
		assert(g.getContent(0, 0) == 1);	// was grid content set?
		g.setContent(Gameboard::MAX_X - 1, Gameboard::MAX_Y - 1, 2);
		assert(g.getContent(Gameboard::MAX_X - 1, Gameboard::MAX_Y - 1) == 2); // was grid content set?
		g.setContent(Gameboard::MAX_X - 1, Gameboard::MAX_Y - 1, Gameboard::EMPTY_BLOCK);
		assert(g.getContent(Gameboard::MAX_X - 1, Gameboard::MAX_Y - 1) == Gameboard::EMPTY_BLOCK); // was grid content set?

		// test setGridContent(Point, content)
		g.setContent(Point(0, 0), 5);
		assert(g.getContent(0, 0) == 5);

		// test setContent(std::vector<Point> locs, int content);
		std::vector<Point> pointsToSet = { Point(0,0), Point(1,1) };
		g.setContent(pointsToSet, 4);
		assert(g.getContent(0, 0) == 4 && g.getContent(1, 1) == 4);


		// test fillRow() & isRowCompleted()
		g.fillRow(0, 1);
		assert(g.getContent(0, 0) == 1);	// is the first spot in the row what we expect?
		assert(g.getContent(Gameboard::MAX_X - 1, 0) == 1);  // is the last spot in the row what we expect?
		assert(g.isRowCompleted(0) == true);	// was row 0 completed?

		// test isRowCompleted()
		g.setContent(0, 0, Gameboard::EMPTY_BLOCK);
		assert(g.isRowCompleted(0) == false);	// did a single incomplete entry make the row incomplete?

		// test clearRow()
		g.fillRow(0, 1);
		assert(g.isRowCompleted(0) == true);	// ensure row filled
		g.fillRow(0, Gameboard::EMPTY_BLOCK);
		assert(g.isRowCompleted(0) == false);	// did row 0 get cleared

		// test isEmpty
		g.empty();
		assert(TestSuite::isGameboardEmpty(g) == true);
		g.setContent(0, 0, 1);
		assert(TestSuite::isGameboardEmpty(g) == false);
		g.empty();
		assert(TestSuite::isGameboardEmpty(g) == true);

		// test empty()
		for (int y = 0; y < Gameboard::MAX_Y; y++) {	// fill the whole board
			g.fillRow(y, 1);
		}
		g.empty();	// empty the board
		assert(TestSuite::isGameboardEmpty(g) == true); // verify the board is empty

		// test copyRowIntoRow()
		g.empty();
		assert(g.isRowCompleted(1) == false);
		for (int x = 0; x < Gameboard::MAX_X; x++) {  // fill row 0 with 0, 1, 2, 3,...
			g.setContent(x, 1, x);
		}
		g.copyRowIntoRow(1, 3);					// copy row 0 into row 1
		assert(g.isRowCompleted(3) == true);	// row 3 should now be completed
		for (int x = 0; x < Gameboard::MAX_X; x++) {
			assert(g.getContent(x, 1) == g.getContent(x, 3)); // compare row 1 with row 3, does it match?
		}

		// test removeRow()
		g.fillRow(0, 0);
		g.fillRow(1, 1);
		g.fillRow(2, 2);
		g.removeRow(2);
		assert(g.getContent(0, 0) == Gameboard::EMPTY_BLOCK);
		assert(g.getContent(0, 1) == 0);
		assert(g.getContent(0, 2) == 1);

		// test removeRows()
		g.empty();
		g.fillRow(0, 0);
		g.fillRow(1, 1);
		g.fillRow(2, 2);
		g.fillRow(3, 3);
		g.fillRow(4, 4);
		std::vector<int> rowsToRemove = { 1, 3 };
		g.removeRows(rowsToRemove);
		assert(g.getContent(0, 0) == Gameboard::EMPTY_BLOCK);
		assert(g.getContent(0, 1) == Gameboard::EMPTY_BLOCK);
		assert(g.getContent(0, 2) == 0);
		assert(g.getContent(0, 3) == 2);
		assert(g.getContent(0, 4) == 4);

		// test getCompletedRowIndices()
		g.empty();
		assert(g.getCompletedRowIndices().size() == 0);
		g.fillRow(2, 1);	// complete row 2
		g.fillRow(4, 1);	// complete row 4
		std::vector<int> completedRows = g.getCompletedRowIndices();
		assert(completedRows.size() == 2 && completedRows[0] == 2 && completedRows[1] == 4); // did it return the right rows?

		// test removeCompletedRows()
		g.empty();
		assert(g.removeCompletedRows() == 0);
		g.fillRow(1, 2);
		g.fillRow(3, 2);
		assert(g.removeCompletedRows() == 2);
		assert(TestSuite::isGameboardEmpty(g) == true);

		// test if a row gets moved down by removeCompletedRows()
		g.empty();
		g.fillRow(0, 0);
		g.fillRow(1, 1);
		g.fillRow(2, 2);
		g.fillRow(3, 3);
		g.setContent(0, 0, Gameboard::EMPTY_BLOCK);
		g.setContent(0, 1, Gameboard::EMPTY_BLOCK);
		g.setContent(0, 2, Gameboard::EMPTY_BLOCK);
		// at this point row 3 is the only complete row
		g.removeCompletedRows();
		assert(g.getContent(1, 0) == Gameboard::EMPTY_BLOCK);
		assert(g.getContent(1, 1) == 0);	// row 0 copied into row 1
		assert(g.getContent(1, 2) == 1);	// row 1 copied into row 2
		assert(g.getContent(1, 3) == 2);	// row 2 copied into row 3
		assert(g.getContent(1, 4) == Gameboard::EMPTY_BLOCK);	// row 4 is still empty


		// test areLocsEmpty()
		g.empty();
		g.fillRow(2, 2);
		std::vector<Point> testPoints;
		testPoints.push_back(Point(0, 0));
		testPoints.push_back(Point(1, 1));
		testPoints.push_back(Point(3, 3));
		assert(g.areLocsEmpty(testPoints) == true);  // should return true since all points are empty
		testPoints.push_back(Point(2, 2));
		assert(g.areLocsEmpty(testPoints) == false);  // should return false since 2,2 contains content 2

		// lastly do a visual printout of an empty board
		g.empty();
		g.printToConsole();
		std::cout << "\n";
		// print out the board with filled in rows)
		for (int y = 0; y < Gameboard::MAX_Y; y++)
		{
			g.fillRow(y, y % 10);
		}
		g.printToConsole();
		std::cout << "\n";
		// print out the board with completed rows removed (should be empty)
		g.removeCompletedRows();
		g.printToConsole();

		std::cout << "passed!" << "\n";
		return true;
	}
#endif


};
#endif /* TESTSUITE_H */