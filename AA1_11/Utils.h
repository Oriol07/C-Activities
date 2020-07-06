#pragma once
#include <iostream>

namespace Utils
{
	void print(int a[], int size) {
		for (int i = 0; i < size; i++)
		{
			std::cout << a[i] << ' ';
		};
		std::cout << std::endl;
	};

	int * generate(int size, long max) {
		int *temp = new int[size];
		for (int i = 0; i < size; i++) { temp[i] = rand() % (max + 1); }
		return temp;
	};

	int * copy(int a[], int length)
	{
		int * tmp = new int[length];
		for (int i = 0; i < length; i++) tmp[i] = a[i];
		return tmp;

	}

	int * reverse(int a[], int length)
	{
		int *res = new int[length];
		for (int i = 0; i < length; i++)
		{
			res[i] = a[length - 1 - i];
		};
		return res;
	}
}