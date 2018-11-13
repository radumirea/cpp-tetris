#pragma once
#include "Piece.h"

class PlaceException {
	std::string msg;
public:
	PlaceException(std::string m) :msg{ m } {}
	std::string getMsg()const { return msg; }
	/*//functie friend (vreau sa folosesc membru privat msg)
	friend std::ostream& operator<<(std::ostream& out, const RepoException& ex);*/
};

class Pile
{
private:

	int width;
	int height;
	std::vector<std::vector<int>> pile;

public:

	Pile(int width, int height) :width{ width }, height{ height } {

		//initializes the pile dimensions
		pile.resize(height);
		for (int i = 0; i < pile.size(); i++)
			pile[i].resize(width,0);
	};

	//getters
	int getWidth() const { return width; };
	int getHeight() const { return height; };
	std::vector<std::vector<int>> getPile() const { return pile; };

	/*
	checks if there are any complete rows
	returns the number of complete rows
	*/
	int checkRows();

	//remover a specified row
	void removeRow(const int row);

	//adds a piece to the pile
	void addPiece(const Piece& p);

	//clears the pile
	void clear();

};

