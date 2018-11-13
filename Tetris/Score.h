#pragma once
#include<string>

class Score
{
private:

	std::string name; //score owner's name
	int score; //the score itself

public:

	//getters
	std::string getName() const { return name; }
	int getScore() const { return score; }

	//setters
	void setScore(const int newScore) { score = newScore; }

	Score(std::string name, int score) :name{ name }, score{ score } {};
	~Score();
};

