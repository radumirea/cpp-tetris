#pragma once

#include<string>

class Score {
private:
	std::string name;
	int score;

public:
	std::string getName() const { return name; }
	int getScore() const { return score; }
	void setScore(const int newScore) { score = newScore; }

	Score(std::string name, int score) :name{ name }, score{ score } {};
	~Score();
};

