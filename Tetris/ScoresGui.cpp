#include "ScoresGui.h"
#include <cctype>
#include <iomanip>
#include <sstream>

void ScoresGui::initComp() {
	setWindowModality(Qt::ApplicationModal);
	table = new QTableWidget();
	vb = new QVBoxLayout();
	this->setLayout(vb);
	table->setColumnCount(2);
	table->setRowCount(10);
	table->setEditTriggers(QAbstractItemView::NoEditTriggers);
	table->verticalHeader()->setVisible(false);
	table->horizontalHeader()->setVisible(false);
	vb->addWidget(table);
}

void ScoresGui::reloadTable() {
	auto scores = serv.sortScore();
	table->clear();
	table->setRowCount(scores.size());
	int i = 0;
	for (const auto& sc : scores) {
		table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(sc.getName())));
		table->setItem(i, 1, new QTableWidgetItem(QString::number(sc.getScore())));
		i++;
	}
}

ScoresGui::~ScoresGui() {}

void ScoresGui::update() {
	reloadTable();
}

void ScoreInputGui::initComp() {
	setWindowModality(Qt::ApplicationModal);
	vb = new QVBoxLayout();
	this->setLayout(vb);
	this->setStyleSheet("background-color: #111111; color: #cccccc; font-size: 20px");

	lblTitle = new QLabel("Submit your score");
	lblTitle->setStyleSheet("font-size: 30px; padding-bottom: 10px");
	lblScore = new QLabel("Score: "+ QString::number(boardgame.getScore()));
	lblName = new QLabel("Name: ");
	txtName = new QLineEdit;
	submit = new QPushButton("Submit");
	cancel = new QPushButton("Cancel");

	input = new QWidget();
	fl = new QFormLayout();
	input->setLayout(fl);
	fl->addRow(lblScore);
	fl->addRow(lblName, txtName);

	vb->addWidget(lblTitle);
	vb->setAlignment(lblTitle, Qt::AlignHCenter);
	vb->addWidget(input);
	vb->addWidget(submit);
	vb->addWidget(cancel);
	vb->addStretch();
}

void ScoreInputGui::connectSlots() {
	QObject::connect(submit, &QPushButton::clicked, this, &ScoreInputGui::addScore);
	QObject::connect(cancel, &QPushButton::clicked, this, &ScoreInputGui::closeWindow);
}

void ScoreInputGui::addScore() {
	if (txtName->text().toStdString() != "") {
    	serv.saveScore(txtName->text().toStdString(), boardgame.getScore());
    
		ScoresGui *scores = new ScoresGui(serv);
		scores->show();
		this->close();
	}
}

void ScoreInputGui::closeWindow() {
	this->close();
}