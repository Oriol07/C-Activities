#pragma once
#include "Types.h"

class  Weapon {

public:
	Ball *balls;
	int  capacityMunition;
	int munition;

	Weapon()
	{
		capacityMunition = 50;
		munition = capacityMunition;
		balls = new Ball[capacityMunition];
	}

	void loadWeapon(int addBullets)
	{
		if ((addBullets + munition) >= capacityMunition) capacityMunition = (addBullets + munition) * 2;
			
			for (int i = 0; i < addBullets; i++)
			{
				munition++;
			}	
	}
};

class Player 
{
public:
	int pos;
	std::string name;
	Weapon weapon;




	Player()
	{
		Init("P1", 0);
	};

	void Init(std::string _n, int _p)
	{
		pos = _p;
		name = _n;
	}

	Ball Shoot()
	{
		Ball b;
		if (weapon.munition > 0)
		{
			b = weapon.balls[weapon.munition];
			weapon.munition--;
			return b;
		}
		
	}

};