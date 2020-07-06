#include "Panel.h"

Panel::Panel()
{
}

Panel::Panel(int size)
{
	for (int i = 0; i < size; i++) {
		if (i == 0 || i == 1) panel.push_back(Ball(rand() % (int)Ball::MAX));

		bool repeat = true;

		do {
			panel.push_back(Ball(rand() % (int)Ball::MAX));
			if (panel[i] == panel[i - 1] && panel[i] == panel[i - 2]) {
				panel.push_back(Ball(rand() % (int)Ball::MAX));
			}
			else repeat = false;

		} while (repeat);
	}
}

int Panel::getSize()
{
	return size;
}

inline void Panel::insert(int position, Ball ball) {

	panel.insert(panel.begin() + 3, ball);
}

inline int Panel::verifier(int position, Ball ball) {
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

inline void Panel::deleteThree(int position) {

	panel.erase(panel.begin() + position, panel.begin() + position + 2);
}

inline void Panel::insertThree() {
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

inline std::string Panel::getBallString(Ball b) {
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

inline void Panel::printPanel() {

	for (auto e : panel) std::cout << getBallString(e) << " ";
}
