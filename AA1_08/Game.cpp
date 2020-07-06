#include <iostream>
#include <vector>
#include <set>
#include <stack>

#include "Card.h"
#include "Gamer.h"
#include "Game.h"



Game::Game()
{
	for (int i = 0; i < players.size(); i++)
	{
		players.at(i).SetID("p" + i);
	}
}


Game::~Game()
{
}
