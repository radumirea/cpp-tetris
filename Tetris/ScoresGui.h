#pragma once
#include "Service.h"
#include "Observ.h"
#include "Boardgame.h"

#include <QtWidgets/QMainWindow>
#include <QtWidgets>
#include <vector>
#include <string>
typedef unsigned char BYTE;

class ScoreInputGui : public QWidget {
private:
	Service& serv;
	Boardgame& boardgame;
	QLabel *lblScore;
	QLabel *lblName;
	QLabel *lblTitle;
	QLineEdit *txtName;
	QPushButton* submit;
	QPushButton* cancel;
	QVBoxLayout *vb;
	QFormLayout *fl;
	QWidget *input;
	
	void initComp();
	void connectSlots();
	void addScore();
	void closeWindow();
	std::string encrypt(std::string);
	std::string base64_encode(BYTE const* buf, unsigned int bufLen);
	std::vector<BYTE> base64_decode(std::string const&);

public:
	ScoreInputGui(Service & serv, Boardgame& boardgame) :serv{ serv }, boardgame{ boardgame } {
		initComp();
		connectSlots();
	};
};

class ScoresGui: public QWidget, public Subject {
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

