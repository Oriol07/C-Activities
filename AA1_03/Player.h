#pragma once

//1
enum Movement { UP, DOWN, LEFT, RIGHT, LAST};

//A vector to save the position of the player;
struct Position {
	int x;
	int y;
};

class Player
{
private:
	int score;
	Movement movToDo;

public:
	Position pos;
	Player();
	~Player();

	void addScore(); // 6
	void setPos(int x, int y); //7
	Position getPos(); 
	int getScore();
	void printScore();
};

