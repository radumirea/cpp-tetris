#pragma once
#include <QtWidgets>
#include "Boardgame.h"
#include "Observ.h"

class Display : public QWidget, public Observer {
private:
	Boardgame & board;
	QVBoxLayout *vb;
	QLabel *lblScore;
	QLabel *lblNextPiece;
	QLabel *lblLevel;
	QLabel *lblLines;
	//components for next piece display
	QGraphicsView *v;
	QGraphicsScene *scene;
	QGraphicsRectItem *rect;
	std::vector<QColor> colors{ "#b53838","#28825d","#bab220","#8d2696","#187498" };
	void initComp();
public:
	Display(Boardgame & board) : board{ board } {
		initComp();
	};
	~Display();
	void update() override;
};

