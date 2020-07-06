#include "Player.h"

Player::Player()
{
}

Player::Player(std::string name, int position) {
	//Player attributes
	id = name;
	pos = position;
	score = 0;

	//Gun
	magSize = 20;
	magCapacity = magSize;

	mag = new Ball[magCapacity];

	//Initialize gun with random balls
	for (int i = 0; i < magSize; i++)
		mag[i] = Ball(rand() % (int)Ball::MAX);
}

int Player::getMagSize()
{
	return magSize;
}

Ball Player::shoot() {
	Ball aux = mag[0];

	Ball *magAux = new Ball[magSize - 1];

	//Copy the array
	for (int i = 0; i < magSize - 1; i++) {
		magAux[i] = mag[i + 1];
	}
	mag = magAux;

	return aux;
}

std::string Player::getMagString(Ball b) {
	std::string s;

	switch (b)
	{
	case Ball::GREEN:
		s = "G";
		break;
	case Ball::ORANGE:
		s = "O";
		break;
	case Ball::YELLOW:
		s = "Y";
		break;
	case Ball::BLUE:
		s = "B";
		break;
	case Ball::RED:
		s = "R";
		break;
	default:
		s = "Something went wrong";
		break;
	}

	return s;
}

void Player::printMagazine() {
	for (int i = 0; i < magSize; i++) {
		std::cout << getMagString(mag[i]) << " ";
	}
}

Player::~Player()
{
}
