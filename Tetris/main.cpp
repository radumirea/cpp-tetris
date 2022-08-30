#include "Tetris.h"
#include <QtWidgets/QApplication>
#include "Tests.h"
#include "Gui.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Tests t{};
	//t.run();

	RepoFile repo{ "scores.txt" };
	Service scoreServ{ repo };

	Boardgame b{10,20};
	Gui g{b ,scoreServ};
	g.show();

	return a.exec();
}
