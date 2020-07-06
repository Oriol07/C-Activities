#pragma once
#include "Utilities.h"

class Player {
	//Private attributes
	std::string id;
	int pos;
	int score;

	int magCapacity;
	int magSize;
	Ball *mag;

public:
	//Public attributes

	//Constructors
	Player();
	Player(std::string name, int position);

	//Functions
	int getMagSize();
	Ball shoot();
	std::string getMagString(Ball b);
	void printMagazine();

	//Destructor
	~Player();
};