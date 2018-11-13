#pragma once
#include <vector>

class Piece
{
private:

	int id;
	int x; //horisontal position
	int y; //vertical position
	std::vector<std::vector<int>> shape;
	static int IDs;

public:

	Piece() {};

	Piece(const int x, const int y)
		:id{ generateId() }, x{ x }, y{ y } {
	};

	Piece(const Piece &p2) {

		id = p2.id;
		x = p2.x;
		y = p2.y;
		shape = p2.shape;

	}

	//getters
	int getId() const { return id; };
	int getX() const { return x; };
	int getY() const { return y; };
	std::vector<std::vector<int>> getShape() const { return shape; };

	//setters
	void setShape(const std::vector<std::vector<int>>& newShape) { shape = newShape; };
	void setX(const int x) { this->x=x; };
	void setY(const int y) { this->y=y; };

	//generates a new id
	const static int generateId() {
		IDs++;
		return IDs;
	}

	//rotates the shape clockwise
	void rotate();

	//moves the shape to the right
	void moveRight();
	//moves the shape to the left
	void moveLeft();
	//moves the shape downward
	void moveDown();
	//checks if the piece has dimensions
	bool hasBody() const;
	
};

