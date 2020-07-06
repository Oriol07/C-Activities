#include "AA1_09.h"

//Comparations Functions
bool comparator(int first, int second)
{
	return first > second;
}
bool isListOrdered(std::list<int> l1)
{
	std::list<int>::iterator it2;
	for (std::list<int>::iterator it = l1.begin(); it != l1.end(); it++)
	{
		if (it == l1.begin())
		{
			it2 = it;
			it++;
		} 
		if (*it2 < *it)
			return false;
			it2 = it;
	}
	return true;
}

//1. SuperMerge
std::list<int> superMerge(std::list<int> l1, std::list<int> l2)
{
	try 
	{
		if (!isListOrdered(l1) || !isListOrdered(l2))
		{
			throw "ERROR: Las std::list<int> recibidas deberian estar ordenadas de mayor a menor.";
		}
		else
		l1.merge(l2, comparator);
		return l1;
	}
	catch(const char* date)
	{
		std::cout << date << std::endl;
		std::list<int> l3;
		return l3;
	}	
}

//2. PrintReverse
void printReverse(std::list<int> l)
{
	for (std::list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// 3. IsBalanced
bool isBalanced(std::list<char> l)
{
	int open = 0;

	for (std::list<char>::iterator it = l.begin(); it != l.end(); it++)
	{
		if (*it == '(') open++;
		else if (*it == ')' && open > 0) open--;
	}

	return (open == 0);
}

// 4. operador << 
std::ostream & operator<<(std::ostream & out, std::list<int> l)
{
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		out << *it <<" ";
	}
	std::cout << std::endl;

	return out;
}
