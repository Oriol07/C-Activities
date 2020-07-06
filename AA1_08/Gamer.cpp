#include <iostream>
#include <set>
#include <list>
#include <string>

#include "Card.h"
#include "Gamer.h"



Gamer::Gamer()
{

}


Gamer::~Gamer()
{

}

void Gamer::InsertCard(Card c)
{
	deck.insert(c);
}

void Gamer::SetID(std::string n)
{
	id = n;
}

Card Gamer::GetCard()
{
	int randOfSize = rand() % deck.size();

	std::set<Card>::iterator it = deck.begin();
	std::advance(it, randOfSize);

	return *it;

}

Card Gamer::GetCard(Suit s)
{
	//With set
	for (auto it = deck.rbegin(); it != deck.rend(); ++it)
	{	
		if (s == (*it).GetType()) return *it;
	}
	/*//With List
	for (auto it = deck2.rbegin(); it != deck2.rend(); ++it)
	{
		if (s == (*it).GetType()) return *it;
	}*/

}

void Gamer::PrintHand()
{
	std::cout << id << ": " << std::endl;	

	for (std::set<Card>::iterator it = deck.begin(); it != deck.end(); ++it)
	{
		
		std::cout << *it << std::endl;
	}
}