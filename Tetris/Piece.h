#pragma once
#include <vector>

class Piece {
private:
	int id;
	int x;
	int y;
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

	int getId() const { return id; };
	int getX() const { return x; };
	int getY() const { return y; };
	std::vector<std::vector<int>> getShape() const { return shape; };
	void setShape(const std::vector<std::vector<int>>& newShape) { shape = newShape; };
	void setX(const int x) { this->x=x; };
	void setY(const int y) { this->y=y; };

	const static int generateId() {
		IDs++;
		return IDs;
	}

	void rotate();
	void moveRight();
	void moveLeft();
	void moveDown();
	bool hasBody() const;
};

