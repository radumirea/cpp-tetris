#include "Piece.h"

int Piece::IDs=0;

void Piece::rotate()
{

	std::vector<std::vector<int>> newShape{ shape };

	//creates the new rotated shape
	for(int i=0;i<shape.size();i++)
		for (int j = 0; j < shape[i].size(); j++) {
			//newShape[MAXLEN-i-1][j] = shape[j][i];
			newShape[j][shape.size() - i - 1] = shape[i][j];
		}

	/*bool movedUp = false;

	//moves shape as far up as possible
	while (movedUp == false) {
		
		for (int i = 0; i < MAXLEN; i++)
			if (newShape[0][i] > 0)
				movedUp = true;

		if (movedUp == false) {

			for (int j = 0; j < MAXLEN-1; j++)
				for (int i = 0; i < MAXLEN-1; i++)
					newShape[i][j] = newShape[i + 1][j];

			for (int i = 0; i < MAXLEN; i++) {
				newShape[MAXLEN-1][i] = 0;
			}
		}

	}

	bool movedLeft = false;

	//moves shape as far left as possible
	while (movedLeft == false) {

		for (int i = 0; i < MAXLEN; i++)
			if (newShape[i][0] > 0)
				movedLeft = true;

		if (movedLeft == false) {

			for (int i = 0; i < MAXLEN-1; i++)
				for (int j = 0; j < MAXLEN-1; j++)
					newShape[i][j] = newShape[i][j+1];

			for (int i = 0; i < MAXLEN; i++) {
				newShape[i][MAXLEN-1] = 0;
			}

		}

	}*/

	setShape(newShape);

	/*//updates the old shape
	for (int i = 0; i<MAXLEN; i++)
		for (int j = 0; j < MAXLEN; j++) {
			shape[i][j] = newShape[i][j];
		}*/

}

void Piece::moveRight()
{
	x++;
}

void Piece::moveLeft()
{
	x--;
}

void Piece::moveDown()
{
	y++;
}

bool Piece::hasBody() const
{
	return !shape.empty();
}
