#pragma once
#include <iostream>
#include <list>

std::list<int> superMerge(std::list<int> l1, std::list<int> l2);
void printReverse(std::list<int> l);
bool isBalanced(std::list<char> l);

std::ostream & operator<<(std::ostream & out, std::list<int> l);