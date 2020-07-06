#include "Player.h"
#include <iostream>


Player::Player()
{
	score = 0;
}


Player::~Player()
{
}



//6
void Player::addScore()
{
	score++;
}

int Player::getScore()
{
	return score;
}

void Player::printScore()
{
	std::cout << std::endl << "Score: " << score << std::endl;
}

//7
void Player::setPos(int x, int y)
{
	pos.x = x;
	pos.y = y;
}

Position Player::getPos()
{
	return pos;
}
