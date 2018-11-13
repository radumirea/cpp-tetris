#include "PieceFactory.h"



PieceFactory::PieceFactory()
{

}


PieceFactory::~PieceFactory()
{
}

Piece PieceFactory::getPiece(const Shape & s, const int c, int x, int y) const
{

	Piece l = Piece(x, y);

	if (s == Shape::L) {

		l.setShape({
			{ 0,c,0 },
			{ 0,c,0 },
			{ 0,c,c }
			});

	}
	else if (s == Shape::J) {

		l.setShape({
			{ 0,c,0 },
			{ 0,c,0 },
			{ c,c,0 }
			});

	}
	else if (s == Shape::T) {

		l.setShape({
			{ 0,0,0 },
			{ 0,c,0 },
			{ c,c,c }
			});

	}
	else if (s == Shape::S) {

		l.setShape({
			{ 0,0,0 },
			{ 0,c,c },
			{ c,c,0 }
			});

	}
	else if (s == Shape::Z) {

		l.setShape({
			{ 0,0,0 },
			{ c,c,0 },
			{ 0,c,c }
			});

	}
	else if (s == Shape::O) {

		/*l.setShape({
		{ c,c },
		{ c,c },
		});*/

		l.setShape({
			{ 0,0,0,0 },
			{ 0,c,c,0 },
			{ 0,c,c,0 },
			{ 0,0,0,0 }
			});

	}
	else if (s == Shape::I) {

		l.setShape({
			{ 0,c,0,0 },
			{ 0,c,0,0 },
			{ 0,c,0,0 },
			{ 0,c,0,0 }
			});

	}

	return l;

}

Piece PieceFactory::randPiece(const int x, const int y) const
{
	//stuff for random generator
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(1.0, 1000.0);

	Shape s = Shape((int)dist(mt) % 7);

	int color = (int)dist(mt) % 5 + 1;

	return getPiece(s, color, x, y);

}
