#include "Tetris.h"
#include <QtWidgets/QApplication>
#include "Tests.h"
#include "Gui.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//Tetris w;
	Tests t{};
	//t.run();

	RepoFile repo{ "scores.txt" };
	Service scoreServ{ repo };

	Boardgame b{10,16};
	Gui g{ b ,scoreServ};
	g.show();

	//w.show();
	return a.exec();
}
