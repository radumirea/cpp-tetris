#include "Boardgame.h"


Boardgame::~Boardgame()
{
}

void Boardgame::nextPiece()
{

	if (!followingPiece.hasBody()) {
		followingPiece = pieceFactory.randPiece(width / 2 - 1, 0);
		followingPiece.setY(followingPiece.getShape().size()*(-1));
	}
	piece = followingPiece;
	followingPiece = pieceFactory.randPiece(width / 2 - 1, 0);
	followingPiece.setY(followingPiece.getShape().size()*(-1));

	/*piece = pieceFactory.randPiece(width/2-1,0);
	piece.setY(piece.getShape().size()*(-1));*/

	notify();

}

bool Boardgame::tick()
{

	movePieceDown();

	return true;

}

bool Boardgame::landed()
{
	if (checkLanded()) {

		/*if (piece.getX() < 0 || piece.getY() < 0) {
		throw PlaceException{ "out of bounds" };
		}*/

		pile.addPiece(piece);
		int l = pile.checkRows();
		lines += l;
		score += l * level;
		nextPiece();
		notify();
		return true;

	}

	return false;
}

bool Boardgame::checkLanded() const
{

	int x = piece.getX();
	int y = piece.getY();

	auto s = piece.getShape();
	auto p = pile.getPile();

	for (int i = 0; i < s.size(); i++)
		for (int j = 0; j < s[0].size(); j++)
			if (((y + i + 1) >= height && s[i][j] > 0) || (y + i + 1 >= 0 && x + j >= 0 && s[i][j] > 0 && p[y + i + 1][x + j] > 0))
				return true;

	return false;

}

bool Boardgame::movePieceRight()
{

	Piece p2 = Piece{ piece };
	p2.moveRight();

	if (!checkCollision(p2)) {
		piece.moveRight();
		landed();
		return true;
	}

	return false;

}

bool Boardgame::movePieceLeft()
{

	Piece p2 = Piece{ piece };
	p2.moveLeft();

	if (!checkCollision(p2)) {
		piece.moveLeft();
		landed();
		return true;
	}

	return false;

}

bool Boardgame::movePieceDown()
{

	Piece p2 = Piece{ piece };
	p2.moveDown();

	if (!checkCollision(p2)) {
		piece.moveDown();
		landed();

		return true;

	}

	return false;

}

void Boardgame::rotatePiece()
{

	Piece p2 = Piece{ piece };

	p2.rotate();

	if (!checkCollision(p2)) {
		piece.rotate();
		landed();
	}

}

bool Boardgame::checkCollision(const Piece & p) const
{

	return checkPileCollision(p) || outOfBounds(p);

}

bool Boardgame::checkPileCollision(const Piece & p) const
{

	if (outOfBounds(p))
		return true;

	int x = p.getX();
	int y = p.getY();

	auto s = p.getShape();

	for (int i = 0; i < s.size(); i++)
		for (int j = 0; j < s[i].size(); j++)
			if ((x + j >= 0 && x + j<width && y + i >= 0 && y + i < height) && pile.getPile()[y + i][x + j] > 0 && s[i][j] > 0)
				return true;

	return false;

}

bool Boardgame::outOfBounds(const Piece & p) const
{

	int x = p.getX();
	int y = p.getY();

	auto s = p.getShape();

	for (int i = 0; i < s.size(); i++)
		for (int j = 0; j < s[0].size(); j++)
			if (s[i][j] > 0 && (j + x >= width || i + y >= height || j + x < 0))
				return true;

	return false;

}

void Boardgame::clear()
{
	pile.clear();
	followingPiece = pieceFactory.getPiece(Shape::Empty, 0, 0, 1);
	score = 0;
	lines = 0;
	level = 1;
}


