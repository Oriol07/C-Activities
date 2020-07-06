#pragma once
class Game
{
private:
	std::vector<Gamer> players;
	std::stack<Card> deck;
	std::stack<Card> discarded;
public:
	Game();
	~Game();
};

