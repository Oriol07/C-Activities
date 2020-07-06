#pragma once
#include "Utilities.h"

struct Panel {
	Ball * panel;
	int size;

	void init() {
		std::cout << "Enter the number of balls: ";
		std::cin >> size;
		std::cout << std::endl;

		panel = new Ball[size];

		for (int i = 0; i < size; i++) {
			if (i == 0) panel[i] = Ball(rand() % (int)Ball::MAX);
			else if (i == 1) panel[i] = Ball(rand() % (int)Ball::MAX);

			bool repeat = true;

			do {
				panel[i] = Ball(rand() % (int)Ball::MAX);
				if (panel[i] == panel[i - 1] && panel[i] == panel[i - 2]) {
					panel[i] = Ball(rand() % (int)Ball::MAX);
				}
				else repeat = false;

			} while (repeat);
		}
	}

	void insert(int position, Ball ball) {
		size += 1;
		Ball *aux = new Ball[size];

		for (int i = 0; i <= size; i++) {
			if (i == 0) aux[i] = ball;
			else aux[i] = panel[i - 1];
		}

		panel = aux;
	}

	int verifier(int position, Ball ball) {
		int aux;
		//Position = left -> right
		if (panel[position] == ball && panel[position + 1] == ball && panel[position + 2] == ball) aux = position;
		//Position = middle
		if (panel[position - 1] == ball && panel[position] == ball && panel[position + 1] == ball) aux = position - 1;
		//Position = right -> left
		if (panel[position - 2] == ball && panel[position - 1] == ball && panel[position] == ball) aux = position - 2;
		else aux = -1;

		return aux;
	}

	void deleteThree(int position) {
		Ball *aux = new Ball[size - 3];
		int j = 0;

		for (int i = 0; i < size; i++) {
			if (i != position || i != position + 1 || i != position + 2) {
				aux[j] = panel[i];
				j += 1;
			}
		}
		size -= 3;

		panel = aux;
	}

	void insertThree() {
		size += 3;
		Ball * aux = new Ball[size];

		for (int i = size - 3; i < size; i++) {
			bool repeat = true;

			do {
				panel[i] = Ball(rand() % (int)Ball::MAX);
				if (panel[i] == panel[i - 1] && panel[i] == panel[i - 2]) {
					panel[i] = Ball(rand() % (int)Ball::MAX);
				}
				else repeat = false;

			} while (repeat);
		}
	}

	std::string getBallString(Ball b) {
		std::string s;

		switch (b)
		{
		case Ball::GREEN:
			s = "G";
			break;
		case Ball::ORANGE:
			s = "O";
			break;
		case Ball::YELLOW:
			s = "Y";
			break;
		case Ball::BLUE:
			s = "B";
			break;
		case Ball::RED:
			s = "R";
			break;
		default:
			s = "Something went wrong";
			break;
		}

		return s;
	}

	void printPanel() {
		for (int i = 0; i < size; i++) {
			std::cout << getBallString(panel[i]) << " ";
		}
	}
};