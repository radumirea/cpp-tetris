#pragma once
#include "Service.h"
#include "Observ.h"
#include "Boardgame.h"

#include <QtWidgets/QMainWindow>
#include <QtWidgets>

class ScoreInputGui : public QWidget
{
private:

	Service& serv;
	Boardgame& boardgame;

	QLabel *lblScore;
	QLabel *lblName;
	QLineEdit *txtName;
	QPushButton* submit;

	QVBoxLayout *vb;
	QFormLayout *fl;
	QWidget *input;

	void initComp();
	void connectSlots();
	void addScore();

public:

	ScoreInputGui(Service & serv, Boardgame& boardgame) :serv{ serv }, boardgame{ boardgame } {
		initComp();
		connectSlots();
	};

};

class ScoresGui: public QWidget, public Subject
{
private:

	Service & serv;

	QTableWidget *table;

	QVBoxLayout *vb;

	void initComp();

	void reloadTable();

public:
	ScoresGui(Service & serv) :serv{ serv } {
		initComp();
		reloadTable();
	};
	~ScoresGui();
	void update();
};

