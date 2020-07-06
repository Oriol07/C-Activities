#include <iostream>
#include <string>
#include <ostream>
#include "Card.h"



Card::Card()
{
	type = Suit::SPADES;
	value = 1;
}
Card::Card(Suit _type, int _value)
{
	type = _type;
	value = _value;
}


Card::~Card()
{
}

Suit Card::GetType() const
{
	return type;
}

int GetValue(const Card &card)
{
	return card.value;
}


bool Card::operator==(const Card &card)
{
	return type == card.type && value == card.value;
}



std::ostream& operator<<(std::ostream& out, const Card& card)
{
	std::string nameType;
	switch (card.type)
	{
	case Suit::SPADES: 
		nameType = "spades";
		break;
	case Suit::CLUBS:
		nameType = "clubs";
		break;
	case Suit::COINS:
		nameType = "coins";
		break;
	case Suit::CUPS:
		nameType = "cups";
		break;
	default:
		nameType = "Fail";

	}
	out << "  - type: " << nameType << " value: " << card.value << " " ;
	std::cout << std::endl;
	return out;

}

bool Card::operator < (const Card &c)
{
	if (type < c.type) return true;
	if (type > c.type)  return false;
	return value > c.value;

} 