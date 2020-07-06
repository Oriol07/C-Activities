#pragma once
#include "Player.h"

//Constants
const int NUM_ROWS = 10;
const int NUM_COLS = 10;
const int NUM_SQUARES = NUM_COLS * NUM_ROWS;

const char COIN = '$';
const char STONE = 'X';
const char PLAYER = 'P';
const char INGET = '*';

class Board
{
private:

	//atr pr
	char board[NUM_ROWS][NUM_COLS];


public:

	//atr pub
	Player player;
	//Constructors
	Board();
	~Board();

	//Functions
	void  initializeBoard(); // 4
	bool checkMovement(Position pos, Movement mov); // 7
	bool existCoin(Position pos, Movement mov); // 8
	void movePlayer(Position &pos, Movement mov); //9
	bool gameOver(); // 10
	void printBoard(); // 11



};

