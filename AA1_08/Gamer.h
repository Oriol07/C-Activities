#pragma once



class Gamer
{
private:
	std::string id;
	std::set<Card, classcomp> deck;
	//std::list<Card> deck2;

public:
	Gamer();
	~Gamer();

	void InsertCard(Card c);
	void SetID(std::string);
	Card GetCard();
	Card GetCard(Suit s);

	void PrintHand();
};

