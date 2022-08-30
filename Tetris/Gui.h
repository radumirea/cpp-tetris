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

class Gui : public QWidget {
private:
	bool gameStateRunning = false;

	Boardgame & board;
	Service& scoreServ;
	//graphics components
	QGraphicsView *v;
	QGraphicsScene *scene;
	QGraphicsRectItem *rect;

	QHBoxLayout *hb;
	QLabel *lblMsg;
	//display for game info
	Display *display;
	QTimer *timer;
	std::vector<QColor> colors{ "#b53838","#28825d","#bab220","#8d2696","#187498" };

	//logic functions
	void keyPressEvent(QKeyEvent * keyevent);
	void tick();

	void initComp();
	void initSlots();

	//game state modifiers
	void startGame();
	void endGame();

	void drawBoard();
	void drawPiece();
	void drawPile();

public:
	Gui(Boardgame & board, Service& scoreServ) : board{ board }, scoreServ{ scoreServ } {
		initComp();
		initSlots();
	};
	~Gui();
};

