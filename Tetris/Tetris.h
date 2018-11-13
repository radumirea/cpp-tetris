#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tetris.h"

class Tetris : public QMainWindow
{
	Q_OBJECT

public:
	Tetris(QWidget *parent = Q_NULLPTR);

private:
	Ui::TetrisClass ui;
};
