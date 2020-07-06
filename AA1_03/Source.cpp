#include <iostream>
#include <ctime>


#include "Board.h"
#include "Player.h"




int main() {

	srand(time(NULL));

	Board board = Board();

	char key = ' ';

	do{
		system("cls");

		board.printBoard();
		board.player.printScore();

		std::cin >> key;

		Movement mov;
		switch (key)
		{
		case 'w': mov = Movement::UP;
			break;
		case 'W': mov = Movement::UP;
			break;
		case 's': mov = Movement::DOWN;
			break;
		case 'S': mov = Movement::DOWN;
			break;
		case 'a': mov = Movement::LEFT;
			break;
		case 'A': mov = Movement::LEFT;
			break;
		case 'd': mov = Movement::RIGHT;
			break;
		case 'D': mov = Movement::RIGHT;
			break;
		default:
			mov = Movement::LAST;
			break;
		};

		if (board.checkMovement(board.player.getPos(), mov))
		{
			if (board.existCoin(board.player.getPos(), mov))
			{
				board.player.addScore();
			}
			board.movePlayer(board.player.pos, mov);
		};

	} while (board.gameOver() == false);


	system("pause");
	return 0;
}