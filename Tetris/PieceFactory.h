#pragma once
#include "Piece.h"
#include <random>

enum class Shape{L,T,Z,S,I,J,O,Empty};

class PieceFactory
{
public:
	PieceFactory();
	~PieceFactory();
	//creates a piece
	Piece getPiece(const Shape& s, const int c, int x, int y) const;
	//creates a piece with randomised shape and color
	Piece randPiece(const int x, const int y) const;
};

