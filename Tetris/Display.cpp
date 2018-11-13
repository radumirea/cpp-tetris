#include "Display.h"

void Display::initComp()
{

	vb = new QVBoxLayout();
	this->setLayout(vb);

	lblScore = new QLabel("Score: 0");
	lblNextPiece = new QLabel("Next Piece");
	lblLevel = new QLabel("Level: 1");
	lblLines = new QLabel("Lines: 0");

	QFont  f;
	f.setPixelSize(20);

	QFont font("Blacklight");
	font.setStyleHint(QFont::Fantasy);
	Display::setFont(font);

	lblScore->setFont(f);
	lblNextPiece->setFont(f);
	lblLevel->setFont(f);
	lblLines->setFont(f);

	vb->addWidget(lblScore);
	vb->addWidget(lblNextPiece);

	scene = new QGraphicsScene();
	v = new QGraphicsView(scene);
	v->setFocusPolicy(Qt::NoFocus);
	v->setFixedSize(70, 70);
	v->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	v->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	v->setStyleSheet("border: 0px");
	//v->setSceneRect(0, 0, 70, 70);

	vb->addWidget(v);

	vb->addWidget(lblLevel);
	vb->addWidget(lblLines);

}

void Display::update()
{

	{

		//updates labels
		lblScore->setText("Score: " + QString::number(board.getScore()));
		lblLevel->setText("Level: " + QString::number(board.getLevel()));
		lblLines->setText("Lines: " + QString::number(board.getLines()));

		scene->clear();

		Piece p = board.getFollowingPiece();
		auto shape = p.getShape();

		std::vector<QColor> color{ "#96251E","#40226B","#348229","#FFDB51","#1A259C" };

		//adjusts view for the following piece
		int scale = v->height() / shape.size();
		v->fitInView(0, 0, 70, 70, Qt::KeepAspectRatio);

		//draws the following piece
		for (int i = 0; i < shape.size(); i++)
			for (int j = 0; j < shape[i].size(); j++)
				if (shape[i][j] > 0) {
					QGraphicsRectItem *r = new QGraphicsRectItem();
					r->setRect(j* scale, i* scale, scale, scale);
					r->setBrush(color[shape[i][j] - 1]);
					scene->addItem(r);

				}

	}

}

Display::~Display()
{
}
