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
		} catch(PlaceException e){
			endGame();
		}
	}
	drawBoard();
}

void Gui::initComp() {
	hb = new QHBoxLayout();
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
	scene = new QGraphicsScene();
	v = new QGraphicsView(scene);
	setLayout(hb);

	v->setFocusPolicy(Qt::NoFocus);
	v->setFixedSize((board.getWidth())*SCALE+3, (board.getHeight())*SCALE+3);
	v->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	v->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	v->setStyleSheet("border: 0px");
	this->setStyleSheet("background-color: #111111; color: #cccccc");

	QGridLayout *layoutt = new QGridLayout(this);
	lblMsg = new QLabel();
	lblMsg->setText("Press Spacebar to\n      start/reset");
	lblMsg->setStyleSheet("padding: 5px; font-size: 20px; text-align: center");
	layoutt->addWidget(v, 0, 0, Qt::AlignCenter);
	layoutt->addWidget(lblMsg, 0, 0, Qt::AlignCenter);
	
	hb->addLayout(layoutt);
	display = new Display(board);
	board.attach(display);
	hb->addWidget(display);
	
	drawBoard();
}

void Gui::initSlots() {
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

void Gui::startGame() {
	lblMsg->setVisible(false);
	board.clear();
	gameStateRunning = true;
	board.nextPiece();
	timer->start(700);
}

void Gui::endGame() {
	lblMsg->setVisible(true);
	gameStateRunning = false;
	timer->stop();
	ScoreInputGui *inputGui = new ScoreInputGui(scoreServ, board);
	//hb->replaceWidget(v,inputGui);
	inputGui->show();
}

void Gui::drawBoard() {
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
	drawPile();
	drawPiece();
}

void Gui::drawPiece() {
	Piece p = board.getPiece();
	auto shape = p.getShape();
	for (int i = 0; i < shape.size(); i++)
		for (int j = 0; j < shape[i].size(); j++)
			if (shape[i][j] > 0 && p.getY()+i>=0 && p.getX()+j>=0) {
				QGraphicsRectItem *r = new QGraphicsRectItem();
				r->setRect((p.getX()+j) * SCALE, (p.getY() + i) * SCALE, SCALE, SCALE);
				r->setBrush(colors[shape[i][j]-1]);
				scene->addItem(r);
			}
}

void Gui::drawPile() {
	Pile p = board.getPile();
	auto pile = p.getPile();
	for (int i = 0; i < pile.size(); i++)
		for (int j = 0; j < pile[i].size(); j++)
			if (pile[i][j] > 0) {
				QGraphicsRectItem *r = new QGraphicsRectItem();
				r->setRect(j * SCALE, i * SCALE, SCALE, SCALE);
				r->setBrush(colors[pile[i][j]-1]);
				scene->addItem(r);
			}
}

Gui::~Gui() {}