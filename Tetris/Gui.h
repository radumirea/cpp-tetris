#pragma once

#define SCALE 25

#include <QtWidgets/QMainWindow>
#include <QtWidgets>
#include "Display.h"
#include "Boardgame.h"
#include "ScoresGui.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <QColor>

class Gui : public QWidget
{
private:

	bool gameStateRunning = false;

	Boardgame & board;

	Service& scoreServ;

	//graphics components
	QGraphicsView *v;
	QGraphicsScene *scene;
	QGraphicsRectItem *rect;

	QHBoxLayout *hb;

	//display for game info
	Display *display;

	QTimer *timer;

	//logic functions
	void keyPressEvent(QKeyEvent * keyevent);
	void tick();

	//inits
	void initComp();
	void initSlots();

	//game state modifiers
	void startGame();
	void endGame();

	//draw functions
	void drawBoard();
	void drawPiece(std::vector<QColor> color);
	void drawPile(std::vector<QColor> color);

public:
	Gui(Boardgame & board, Service& scoreServ) : board{ board }, scoreServ{ scoreServ } {
		initComp();
		initSlots();
	};
	~Gui();
};

