#include "Tetris.h"
#include <QtWidgets/QApplication>
#include "Tests.h"
#include "Gui.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//Tetris w;
	qDebug("aaa");
	Tests t{};
	//t.run();

	Boardgame b{10,16};
	Gui g{ b };
	g.show();

	//w.show();
	return a.exec();
}
