#pragma once
#include "AA1_09.h"

int main() {
	std::list<int> l1({ 20,10,8 });
	std::list<int> l2({40, 30, 15, 7, 2});
	std::list<char> l3({ '(', '(', '(', ')', '(', ')', ')', ')', '(', ')' });
	std::list<char> l4({ '(', '(', ')', ')', ')', '(' });


	std::list<int> sMerge = superMerge(l1, l2);
	std::cout << sMerge;
	std::cout << l1;

	printReverse(sMerge);

	bool l3Balanced = isBalanced(l3);
	bool l4Balanced = isBalanced(l4);

	return 0;
}