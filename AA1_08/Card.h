#pragma once

enum Suit { SPADES, COINS, CUPS, CLUBS };



class Card
{	
	
public:
	
	int value;
	Suit type;

	Card();
	Card(Suit _t, int _v);
	~Card();
	
	Suit GetType() const;
	friend int GetValue(const Card &card);

	bool operator==(const Card &c);
	bool operator < (const Card &c);

	friend std::ostream& operator<<(std::ostream& out, const Card& c);

};

struct classcomp {
	bool operator()(const Card &card, const Card &card2) const
	{
		if (static_cast<int>(card.type) < static_cast<int>(card2.type)) return true;
		if (static_cast<int>(card.type) > static_cast<int>(card2.type)) return false;
		return card.value > card2.value;
	}

};