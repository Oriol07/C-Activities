#pragma once

//Exercise 2
//A
std::vector<int> addVectors(std::vector<int> v1, std::vector<int> v2)
{
	for (int i = 0; i < v1.size() && v2.size(); i++)
	{
		if (v1.size() > v2.size())
			v1[i] += v2[i];
		else
			v2[i] += v1[i];
	}

	if (v1.size() > v2.size())
		return v1;
	else
		return v2;
}

//B
std::vector<std::string> concatVectors(std::vector<std::string> v1, std::vector<std::string> v2)
{
	v1.insert(v1.end(), v2.begin(), v2.end());
	return v1;
}

//C
void shiftRight(std::vector<int> &v1)
{

	std::rotate(v1.rbegin(), v1.rbegin() + 1, v1.rend());
	v1[0] = rand() % 10;

}

//D
void rotateLeft(std::vector<int> &v1)
{
	int arr = v1[0];

	std::rotate(v1.begin(), v1.begin() + 1, v1.end());
}

//E
void searchAdjacent(std::vector<int> &v1)
{
	int counterSameNum = 0;
	int passNum = v1[0];
	std::vector<int>::iterator it, it2;
	it = v1.begin();
	it2 = v1.begin();
	int i = 1;
	while (i < v1.size())
	{
		//Comprova si el numero de la posició es el mateix que el de la posició antrior
		if (v1[i] == passNum)
			counterSameNum++;
		else
			counterSameNum = 0;

		passNum = v1[i];

		//si entres es que el numero esta repetit 3 vegades
		if (counterSameNum > 1)
		{
			advance(it,i - 2);
			advance(it2,i + 1);
			v1.erase(it, it2);
			//new elements
			for (int j = 0; j < 3; j++)
			{
				v1.push_back(rand() % 10);
			}
			//tornem a posar el contador a 0 per si hi han mes numeros consecutius tres cops
			counterSameNum = 0; 
			i -= 3;
			it = v1.begin();
			it2 = v1.begin();

		}
		i++;
	}

}
//F
bool isPalindrome(std::vector<char> v1)
{
	for (int i = 0; i < (v1.size() - 1) / 2; i++)
	{
		if (v1[i] != v1[(v1.size() - 1) - i])
		{
			return false;
		}
	}
	return true;
}