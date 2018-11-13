#pragma once
#include "Pile.h"
#include "PieceFactory.h"
#include "Observ.h"

class Boardgame : public Subject
{
private:

	int width;
	int height;

	int score = 0;
	int lines = 0;
	int level = 1;

	Pile pile;
	PieceFactory pieceFactory;
	Piece piece;
	Piece followingPiece;

public:
	Boardgame(int width, int height) :width{ width }, height{ height }, pile { Pile(width, height) }, pieceFactory{ PieceFactory() } {};
	~Boardgame();

	//getters
	int getWidth() const { return width; };
	int getHeight() const { return height; };
	int getScore() const { return score; };
	int getLines() const { return lines; };
	int getLevel() const { return level; };
	Piece getPiece() const { return piece; };
	Piece getFollowingPiece() const { return followingPiece; };
	Pile getPile() const { return pile; };

	//generates the next piece (and the following one)
	void nextPiece();

	//actions that perform every set time
	bool tick();

	/*
	checks if current piece has landed
	if so, sticks it to the pile, updates session info
	*/
	bool landed();

	//checks if current piece has landed
	bool checkLanded() const;

	//moves piece right if possible
	bool movePieceRight();

	//moves piece left if possible
	bool movePieceLeft();

	//moves piece down if possible
	bool movePieceDown();

	//rotates the piece clockwise if possible
	void rotatePiece();

	//checks if piece collides in any way
	bool checkCollision(const Piece& p) const;

	//checks if a piece is colliding with the pile
	bool checkPileCollision(const Piece& p) const;

	//checks if piece is out of bounds
	bool outOfBounds(const Piece& p) const;

	//resets the session
	void clear();

};

