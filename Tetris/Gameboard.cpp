#include <vector>
#include "Point.h"
#include "Gameboard.h"
#include <cassert>
#include <iomanip>

Gameboard::Gameboard() {
	
	empty();
}

int Gameboard::getContent(const Point& pt) const {

	assert(isValidPoint(pt));

	return grid[pt.getY()][pt.getX()];
}

int Gameboard::getContent(int x, int y) const {

	assert(isValidPoint(x, y));

	return grid[y][x];
}

Point Gameboard::getSpawnLoc() {
	Point pt = spawnLoc;
	return pt;
}

void Gameboard::setContent(const Point& pt, int content) {
	assert(isValidPoint(pt));
	grid[pt.getY()][pt.getX()] = content;
}

void Gameboard::setContent(int x, int y, int content) {
	assert(isValidPoint(x, y));
	grid[y][x] = content;
}

void Gameboard::setContent(const std::vector<Point>& locs, int content) {
	
	for (const Point& pt : locs) {
		if (isValidPoint(pt)) {
			grid[pt.getY()][pt.getX()] = content;
		}
	}

}

bool Gameboard::areLocsEmpty(std::vector<Point> locs) const {
	
	for (Point& pt : locs) {
		if (isValidPoint(pt)) {
			if (grid[pt.getY()][pt.getX()] != EMPTY_BLOCK) {
				return false;
			}
		}
	}

	return true;
}

int Gameboard::removeCompletedRows() {

	int size = getCompletedRowIndices().size();

	removeRows(getCompletedRowIndices());

	return size;
}

void Gameboard::empty() {

	for (int col = 0; col < MAX_Y; col++) {
		for (int row = 0; row < MAX_X; row++) {
			grid[col][row] = EMPTY_BLOCK;
		}
	}
}

void Gameboard::printToConsole() const {

	std::cout << "GAMEBOARD" << '\n';

	for (int col = 0; col < MAX_Y; col++) {
		for (int row = 0; row < MAX_X; row++) {
			std::cout << std::setw(2) << grid[col][row];
		}
		std::cout << '\n';
	}
}

bool Gameboard::isRowCompleted(int rowIndex) const {

	for (int col = 0; col < MAX_X; col++) {
		if (grid[rowIndex][col] == EMPTY_BLOCK) {
			return false;
		}
	}

	return true;
}

std::vector<int> Gameboard::getCompletedRowIndices() const {

	std::vector<int> completedRows{};

	for (int row = 0; row < MAX_Y; row++) {
		if (isRowCompleted(row)) {
			completedRows.push_back(row);
		}
	}

	return completedRows;
}

void Gameboard::removeRow(int rowIndex) {

	for (int row = rowIndex; row > 0; row--) {
		copyRowIntoRow(row - 1, row);
	}

	fillRow(0, EMPTY_BLOCK);

}

void Gameboard::removeRows(const std::vector<int>& rowIndices) {
	for (int row : rowIndices) {
		removeRow(row);
	}
}

void Gameboard::fillRow(int rowIndex, int content) {
	for (int col = 0; col < MAX_X; col++) {
		grid[rowIndex][col] = content;
	}
}

void Gameboard::copyRowIntoRow(int sourceRowIndex, int targetRowIndex) {

	for (int col = 0; col < MAX_X; col++) {
		grid[targetRowIndex][col] = grid[sourceRowIndex][col];
	}
}

bool Gameboard::isValidPoint(const Point& p) const {
	
	int x = p.getX();
	int y = p.getY();

	return isValidPoint(x, y);

}

bool Gameboard::isValidPoint(int x, int y) const {

	if (x >= MAX_X || x < 0 || y >= MAX_Y || y < 0) {
		return false;
	}

	return true;
}


