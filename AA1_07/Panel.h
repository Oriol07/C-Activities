#pragma once
#include "Utilities.h"

class Panel {
	//Atributtes
	std::vector<Ball> panel;
	int size;

public:
	//Constructor
	Panel();
	Panel(int size);

	//Functions
	int getSize();
	void insert(int position, Ball ball);
	int verifier(int position, Ball ball);
	void deleteThree(int position);
	void insertThree();
	std::string getBallString(Ball b);
	void printPanel();
};