#pragma once
#include "Piece.h"
#include <string>

class PlaceException {
	std::string msg;
public:
	PlaceException(std::string m) :msg{ m } {}
	std::string getMsg()const { return msg; }
};

class Pile {
private:
	int width;
	int height;
	std::vector<std::vector<int>> pile;

public:
	Pile(int width, int height) :width{ width }, height{ height } {
		pile.resize(height);
		for (int i = 0; i < pile.size(); i++)
			pile[i].resize(width,0);
	};

	int getWidth() const { return width; };
	int getHeight() const { return height; };
	std::vector<std::vector<int>> getPile() const { return pile; };

	/*
	checks if there are any complete rows
	returns the number of complete rows
	*/
	int checkRows();
	void removeRow(const int row);
	void addPiece(const Piece& p);
	void clear();
};

