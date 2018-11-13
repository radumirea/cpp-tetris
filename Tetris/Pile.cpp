#include "Pile.h"




int Pile::checkRows()
{
	int removed = 0;

	for (int i = 0; i < height; i++) {
		bool full = true;
		for (int j = 0; j < width; j++) {

			if (pile[i][j] == 0) {
				full = false;
			}

		}

		if (full == true) {
			removeRow(i);
			removed++;
		}
	}

	return removed;

}

void Pile::removeRow(int row)
{

	for (int i = row; i >= 1; i--) 
		for (int j = 0; j < width; j++) {
			pile[i][j] = pile[i-1][j];
		}

	for (int i = 0; i < width; i++) {
		pile[0][i] = 0;
	}

}

void Pile::addPiece(const Piece& p)
{

	int x = p.getX();
	int y = p.getY();

	std::vector<std::vector<int>> shape = p.getShape();

	for (int i = 0; i < shape.size(); i++) {

		for (int j = 0; j < shape[i].size(); j++) {

			if (shape[i][j] > 0) {

				if(y+i<0 || x+j<0)
					throw PlaceException{ "out of bounds" };
				pile[y + i][x + j] = shape[i][j];
			}

		}

	}

}


void Pile::clear()
{

	for (auto & row : pile)
		for (auto & block : row)
			block = 0;

}



