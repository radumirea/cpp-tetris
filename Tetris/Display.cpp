#include "Display.h"

void Display::initComp()
{
	vb = new QVBoxLayout();
	this->setLayout(vb);

	lblScore = new QLabel("Score:\n0");
	lblNextPiece = new QLabel("Next Piece");
	lblLevel = new QLabel("Level:\n1");
	lblLines = new QLabel("Lines:\n0");
    QFont  f;
	f.setPixelSize(20);

    QFont font("Helvetica");
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

	vb->addWidget(v);
	vb->addWidget(lblLevel);
	vb->addWidget(lblLines);
}

void Display::update() {

	lblScore->setText("Score:\n" + QString::number(board.getScore()));
	lblLevel->setText("Level:\n" + QString::number(board.getLevel()));
	lblLines->setText("Lines:\n" + QString::number(board.getLines()));
	scene->clear();

	Piece p = board.getFollowingPiece();
	auto shape = p.getShape();
	//adjusts view for the following piece
	int scale = v->height() / shape.size();
	v->fitInView(0, 0, 70, 70, Qt::KeepAspectRatio);
	//draws the following piece
	for (int i = 0; i < shape.size(); i++)
		for (int j = 0; j < shape[i].size(); j++)
			if (shape[i][j] > 0) {
				QGraphicsRectItem *r = new QGraphicsRectItem();
				r->setRect(j* scale, i* scale, scale, scale);
				r->setBrush(colors[shape[i][j] - 1]);
				scene->addItem(r);
		}
}

Display::~Display() {
}
