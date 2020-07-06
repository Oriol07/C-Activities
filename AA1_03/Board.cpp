#include "Board.h"
#include "Player.h"
#include <iostream>

//Constructor
Board::Board()
{
	initializeBoard();

}

//Destructor
Board::~Board()
{
}

//4.
void Board::initializeBoard()
{
	int numOfCoins, numOfStones; // the values will be the number of coins or stones in the map;
	int findRow, findCol;
	int percentOfCoins, percentOfStones;

	percentOfCoins = (0.2*NUM_SQUARES);
	percentOfStones = (0.3*NUM_SQUARES);
	//The result will be the number of coins and stones in the map;
	numOfCoins = rand() % percentOfCoins;
	numOfStones = rand() % percentOfStones;

	//Put all the cells to INGET char
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
			board[i][j] = INGET;
		}
	}


	//We find the player position
	findRow = rand() % NUM_ROWS;
	findCol = rand() % NUM_COLS;
	board[findRow][findCol] = PLAYER;
	player.setPos(findRow, findCol);

	//It puts the coins in the cells
	do {
		findRow = rand() % NUM_ROWS;
		findCol = rand() % NUM_COLS;
		if (board[findRow][findCol] != COIN && board[findRow][findCol] != PLAYER)
		{
			board[findRow][findCol] = COIN;
			numOfCoins--;
		}
	} while (numOfCoins > 0);

	//It puts the Stones in the cells
	do {
		findRow = rand() % NUM_ROWS;
		findCol = rand() % NUM_COLS;
		if (board[findRow][findCol] != COIN && board[findRow][findCol] != PLAYER && board[findRow][findCol] != STONE)
		{
			board[findRow][findCol] = STONE;
			numOfStones--;
		}
	} while (numOfStones > 0);
}

//5
bool Board::checkMovement(Position pos, Movement mov)
{
	switch (mov)
	{
	case Movement::LEFT:
		return !(pos.y - 1 < 0 || board[pos.x][pos.y - 1] == STONE);
	case Movement::RIGHT:
		return !(pos.y + 1 > NUM_COLS - 1 || board[pos.x][pos.y + 1] == STONE);
	case Movement::UP:
		return !(pos.x - 1 < 0 || board[pos.x - 1][pos.y] == STONE);
	case Movement::DOWN:
		return !(pos.x + 1 > NUM_ROWS - 1 || board[pos.x + 1][pos.y] == STONE);
	default:
		return 0;
	}

}

//8
bool Board::existCoin(Position pos, Movement mov) {
	switch (mov)
	{
	case Movement::LEFT:
		return (board[pos.x][pos.y - 1] == COIN);
	case Movement::RIGHT:
		return (board[pos.x][pos.y + 1] == COIN);
	case Movement::UP:
		return (board[pos.x - 1][pos.y] == COIN);
	case Movement::DOWN:
		return (board[pos.x + 1][pos.y] == COIN);
	}
}

//10
bool Board::gameOver()
{
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
			if (board[i][j] == COIN)
				return false;
		}
	}
	return true;
}

//10
void Board::movePlayer(Position &pos, Movement mov)
{
	Position newPos = pos;

	//calcular cual seria la nueva posicion
	switch (mov)
	{
	case Movement::LEFT: newPos = { pos.x, pos.y - 1 };
						 break;
	case Movement::RIGHT: newPos = { pos.x, pos.y + 1 };
						  break;
	case Movement::UP: newPos = { pos.x - 1, pos.y };
					   break;
	case Movement::DOWN: newPos = { pos.x + 1, pos.y };
						 break;
	default: newPos = { pos.x, pos.y };
			 break;
	}

	board[pos.x][pos.y] = INGET;
	board[newPos.x][newPos.y] = PLAYER;
	pos = newPos;  //actualiza la posicion del jugador

}


//11
void Board::printBoard()
{
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
			std::cout << board[i][j];
		std::cout << std::endl;
	}
}