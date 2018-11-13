#pragma once
#include <QtWidgets>
#include "Boardgame.h"
#include "Observ.h"

class Display : public QWidget, public Observer
{
private:

	Boardgame & board;

	QVBoxLayout *vb;

	QLabel *lblScore;
	QLabel *lblNextPiece;
	QLabel *lblLevel;
	QLabel *lblLines;

	//components for next piece representation
	QGraphicsView *v;
	QGraphicsScene *scene;
	QGraphicsRectItem *rect;

	void initComp();


public:
	Display(Boardgame & board) : board{ board } {
		initComp();
	};
	~Display();

	void update() override;
};

