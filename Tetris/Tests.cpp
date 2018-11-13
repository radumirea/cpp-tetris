#include "Tests.h"
#include "Pile.h"
#include "Boardgame.h"
#include <assert.h> 
#include <vector>

Tests::Tests()
{
}


Tests::~Tests()
{
}

void Tests::run()
{

	testShape();
	testPile();
	testBoardGame();

}

void Tests::testShape()
{

	PieceFactory pf = PieceFactory();

	Piece l = pf.getPiece(Shape::L, 0, 0,1);

	std::vector<std::vector<int>> shape = {
	{ 1,0,0,0 },
	{ 1,0,0,0 },
	{ 1,1,0,0 },
	{ 0,0,0,0 }
	};

	assert(l.getShape() == shape);

	l.rotate();

	std::vector<std::vector<int>> shape2 = {
	{ 1,1,1,0 },
	{ 1,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
	};

	assert(l.getShape() == shape2);

	l.rotate();

	std::vector<std::vector<int>> shape3 = {
	{ 1,1,0,0 },
	{ 0,1,0,0 },
	{ 0,1,0,0 },
	{ 0,0,0,0 }
	};

	assert(l.getShape() == shape3);

	l.rotate();

	std::vector<std::vector<int>> shape4 = {
	{ 0,0,1,0 },
	{ 1,1,1,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
	};

	assert(l.getShape() == shape4);

	l.rotate();

	assert(l.getShape() == shape);

}

void Tests::testPile()
{

	PieceFactory pf = PieceFactory();

	Pile p = Pile(9,16);
	
	Piece l1 = pf.getPiece(Shape::L, 0, 0,1);
	l1.rotate();
	Piece l2 = pf.getPiece(Shape::L, 3, 0,1);
	l2.rotate();
	Piece l3 = pf.getPiece(Shape::L, 6, 0,1);
	l3.rotate();

	p.addPiece(l1);
	p.addPiece(l2);
	p.addPiece(l3);

	std::vector<std::vector<int>> pile = p.getPile();

	for (int i = 0; i++; i < pile[0].size()) {
		assert(pile[0][i] == 1);
	}

	int r = p.checkRows();

	assert(r == 1);


}

void Tests::testBoardGame()
{

	PieceFactory pf = PieceFactory();

	Boardgame board = Boardgame(10,16);

	board.nextPiece();

	Piece p = board.getPiece();

	assert(p.getX() == 4);
	assert(p.getY() == 0);

	bool mv = board.movePieceRight();

	assert(board.getPiece().getX() == 5);
	assert(mv == true);

	mv = board.movePieceLeft();

	assert(board.getPiece().getX() == 4);
	assert(mv == true);

	mv = board.movePieceLeft();
	mv = board.movePieceLeft();
	mv = board.movePieceLeft();
	mv = board.movePieceLeft();
	mv = board.movePieceLeft();

	assert(board.getPiece().getX() == 0);
	assert(mv == false);

	Piece p2 = pf.getPiece(Shape::L, -1, 1,1);
	assert(board.checkCollision(p2) == true);

}
