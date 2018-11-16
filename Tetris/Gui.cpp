#include "Gui.h"

void Gui::keyPressEvent(QKeyEvent *event) {


	if (event->key() == Qt::Key_Space)
	{
		startGame();
	}

	if (gameStateRunning) {

		try {

			if (event->key() == Qt::Key_Right) {

				board.movePieceRight();
			}
			if (event->key() == Qt::Key_Left) {

				board.movePieceLeft();
			}
			if (event->key() == Qt::Key_Down) {

				board.movePieceDown();
			}
			if (event->key() == Qt::Key_Up) {

				board.rotatePiece();
			}
		}
		catch(PlaceException e){
			endGame();
		}

	}

	drawBoard();

}

void Gui::initComp()
{
	hb = new QHBoxLayout();
	setLayout(hb);

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(tick()));

	scene = new QGraphicsScene();

	//scene->addItem(rect);

	v = new QGraphicsView(scene);
	v->setFocusPolicy(Qt::NoFocus);
	v->setFixedSize((board.getWidth())*SCALE+3, (board.getHeight())*SCALE+3);
	v->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	v->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	v->setStyleSheet("border: 0px");
	this->setStyleSheet("background-color: gray;");


	hb->addWidget(v);

	display = new Display(board);
	board.attach(display);
	hb->addWidget(display);

	drawBoard();
	
}

void Gui::initSlots()
{

	QObject::connect(timer, &QTimer::timeout,this, &Gui::tick);

}

void Gui::tick() {

	try {
		board.tick();
	}
	catch (PlaceException e) {
		endGame();
	}

	timer->setInterval(850 - board.getLevel()*150);

	drawBoard();
	
}

void Gui::startGame()
{
	board.clear();
	gameStateRunning = true;
	board.nextPiece();
	timer->start(700);

}

void Gui::endGame()
{
	gameStateRunning = false;
	timer->stop();

	ScoreInputGui *inputGui = new ScoreInputGui(scoreServ, board);
	//inputGui
	inputGui->show();

}



void Gui::drawBoard()
{

	std::vector<QColor> colors{ "#96251E","#40226B","#348229","#FFDB51","#1A259C" };

	scene->clear();

	Pile p = board.getPile();

	for (int i = 0; i < board.getHeight(); i++) {
		for (int j = 0; j < board.getWidth(); j++) {

			QGraphicsRectItem *r = new QGraphicsRectItem();
			r->setRect(j * SCALE, i * SCALE, SCALE, SCALE);
			r->setBrush(QColor("#313335"));
			scene->addItem(r);

		}
	}

	drawPile(colors);
	drawPiece(colors);

}

void Gui::drawPiece(std::vector<QColor> color)
{

	Piece p = board.getPiece();
	auto shape = p.getShape();

	for (int i = 0; i < shape.size(); i++)
		for (int j = 0; j < shape[i].size(); j++)
			if (shape[i][j] > 0 && p.getY()+i>=0 && p.getX()+j>=0) {
				QGraphicsRectItem *r = new QGraphicsRectItem();
				r->setRect((p.getX()+j) * SCALE, (p.getY() + i) * SCALE, SCALE, SCALE);
				//r->setBrush(Qt::red);
				r->setBrush(color[shape[i][j]-1]);
				scene->addItem(r);
			}

}

void Gui::drawPile(std::vector<QColor> color)
{

	Pile p = board.getPile();
	auto pile = p.getPile();

	for (int i = 0; i < pile.size(); i++)
		for (int j = 0; j < pile[i].size(); j++)
			if (pile[i][j] > 0) {
				QGraphicsRectItem *r = new QGraphicsRectItem();
				r->setRect(j * SCALE, i * SCALE, SCALE, SCALE);
				//r->setBrush(Qt::blue);
				r->setBrush(color[pile[i][j]-1]);
				scene->addItem(r);
			}

}



Gui::~Gui()
{
}
