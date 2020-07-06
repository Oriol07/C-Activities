#pragma once
#include <stdlib.h>

enum Color{GREEN, RED, BLUE, ORANGE, YELLOW, LAST};

class Ball {
private:
	Color color;

public:
	Ball()
	{
		color = Color(rand() % LAST);
	};

};


