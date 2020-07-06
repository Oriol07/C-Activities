#pragma once
#include "Utilities.h"
#include "Panel.h"
#include "Player.h"

int main() {
	srand(time(NULL));

	std::string name;

	int size;
	std::cout << "Enter the number of balls: ";
	std::cin >> size;
	std::cout << std::endl;
	Panel board(size);
	

	std::cout << "Enter player name: ";
	std::cin >> name;
	std::cout << std::endl;
	Player player(name, rand() % board.getSize());


	do {
		//Print panel & player magazine
		board.printPanel();
		std::cout << std::endl << std::endl;
		player.printMagazine();

		int pos;
		std::cout << " Enter position: ";
		std::cin >> pos;


	} while (player.getMagSize() <= 0);


	return 0;
}