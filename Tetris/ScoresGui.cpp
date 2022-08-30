#include "ScoresGui.h"
#include <emscripten/fetch.h>
#include <cctype>
#include <iomanip>
#include <sstream>

void ScoresGui::initComp() {
	setWindowModality(Qt::ApplicationModal);
	table = new QTableWidget();
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
    
    	std::string nameStr = txtName->text().toStdString();
		std::string scoreStr = std::to_string(boardgame.getScore());
		std::string payload = "tetris|" + nameStr + "|" + scoreStr;
		std::string payloadEnc = encrypt(payload);

		emscripten_fetch_attr_t attr;
  		emscripten_fetch_attr_init(&attr);
  		strcpy(attr.requestMethod, "POST");
  		attr.attributes = EMSCRIPTEN_FETCH_LOAD_TO_MEMORY;

		std::vector<BYTE> myData;
		std::copy(payloadEnc.begin(), payloadEnc.end(), std::back_inserter(myData));
		std::string encodedData = base64_encode(&myData[0], myData.size());

  		emscripten_fetch(&attr, ("api/projects/scores?payload=" + encodedData).c_str());
		//ScoresGui *scores = new ScoresGui(serv);
		//scores->show();

		this->close();
	}
}

void ScoreInputGui::closeWindow() {
	this->close();
}

std::string ScoreInputGui::encrypt(std::string msg) {
	//redacted
	return msg;
}

static const std::string base64_chars =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

static inline bool is_base64(BYTE c) {
  return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string ScoreInputGui::base64_encode(BYTE const* buf, unsigned int bufLen) {
  std::string ret;
  int i = 0;
  int j = 0;
  BYTE char_array_3[3];
  BYTE char_array_4[4];

  while (bufLen--) {
    char_array_3[i++] = *(buf++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for(i = 0; (i <4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }

  if (i)
  {
    for(j = i; j < 3; j++)
      char_array_3[j] = '\0';

    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;

    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];

    while((i++ < 3))
      ret += '=';
  }

  return ret;
}