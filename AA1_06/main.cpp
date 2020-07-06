/*********************************
* - AA1_06						 *
* - Oriol Comas Llurià			 * 
*								 *
**********************************/



#include <iostream>
#include <vector>
#include <string>

#include "Persona.h"
#include "VectorFunctions.h"


template <typename T>
void print(const std::vector<T> &v) {
	for (auto const &e : v)
	{
		std::cout << e << "-";
	}
	std::cout << std::endl;
}

int main()
{
	struct date {
		int day, month, year;
		date(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {};
		date() :day(0), month(0), year(0) {};
	};

	std::vector<person>v63({ { "Pepe",date(12,12,2000),"1232456X" },{ "Pepito",date(12,12,2001),"6543211X" },{ "Jose",date(12,12,2002),"88888888T" } });
	std::vector<person>v61(3);

	std::vector<int>vvv(10, 1);

	//Ejercicio 2 (uso de las funciones)
	//A addVectors
	std::vector<int> v11({ 10,20,30 });
	std::vector<int> v12(v11);
	std::vector<int> v13 = addVectors(v11, v12);
	std::cout << "A(20-40-60):";
	print<int>(v13);

	//B concatVectors
	std::vector<std::string> vb1({ "dabale" ,"arroz","a","la","zorra" });
	std::vector<std::string> vb2({ "el","abad" });
	concatVectors(vb1, vb2);
	std::cout << "B(dabalearrozalazorraelabad):";
	print<std::string>(vb1);

	//C shiftRight
	shiftRight(v11);
	std::cout << "C(X,10,20):";
	print<int>(v11);

	//D rotateLeft
	std::vector<int> v22({ 10,20,30,40,50 });
	rotateLeft(v22);
	std::cout << "D(20,30,40,50,10):";
	print<int>(v22);

	//E searchAdjacent
	std::vector<int>ve1({ 1,2,2,2,3,4,5 });
	searchAdjacent(ve1);
	std::cout << "E(1,X,X,X,3,4,5):";
	print<int>(ve1);

	std::vector<int>ve2({ 1,2,2,3,4,5 });
	searchAdjacent(ve2);
	std::cout << "E(1,2,2,3,4,5):";
	print<int>(ve2);

	std::vector<int>ve3({ 1,2,2,3,4,5,5,5 });
	searchAdjacent(ve3);
	std::cout << "E(1,2,2,3,4,X,X,X):";
	print<int>(ve3);

	//F isPalindrome
	std::vector<char> fraseSi({ 'd','a','b','a','l','e',' ' ,'a','r','r','o','z',' ' ,'a',' ' ,'l','a',' ' ,'z','o','r','r','a',' ' ,'e' ,'l',' ' ,'a','b','a','d' });
	std::cout << "¿Es palindromo?si" << (isPalindrome(fraseSi)) ? "si" : "no";

	std::vector<char> fraseNo({ 'd','a','b','a','l','e',' ' ,'s','o','p','a',' ' ,'a',' ' ,'l','a',' ' ,'z','o','r','r','a',' ' ,'e' ,'l',' ' ,'a','b','a','d' });
	std::cout << "¿Es palindromo?no" << (isPalindrome(fraseNo)) ? "si" : "no";



	return 0;
};




//int main()
//{
//	// Exercise 1
//	std::vector<int> v1(5);
//	std::vector<int> v2(10, 1);
//	std::vector<int> v3{ 10,9,8,7,6,5,4,3,2,1 };
//	std::vector<std::string> v4{ "Gertrudiz", "Pancracia", "Anacleto", "Hipolito", "Corona", "Fulgencia" };
//	std::vector<int> v5(v3);
//	std::vector<Persona> v6{ { v4[0], "32451236Q", 10,8,2000 },{ v4[4], "00000666Q", 6,6,666  },{ "Maite", "12345678A",1,2,1900 } };
//
//	for (Persona x : v6)
//		std::cout << x.name <<" " << x.dni << " " << x.birthday.day <<'/' << x.birthday.month << '/' << x.birthday.year << std::endl;
//
//	//Exercise 3
//
//	//A
//	std::vector<int> v7 = addVectors(v3, v2);
//	
//	std::cout<< " A: " << std::endl;
//	for (int x : v7)
//	{
//		std::cout << " - " << x << std::endl;
//	}
//
//
//	//B
//	std::vector<std::string> v8{ "AAA", "BBB", "CCC", "DDD", "EEE" };
//	std::vector<std::string> v9 = concatVectors(v4, v8);
//	std::cout << " B: " << std::endl;
//	for (std::string x : v9)
//	{
//		std::cout << " - " << x << std::endl;
//	}
//
//
//	//C
//	std::vector<int> v21({ 10,20,30 });
//	shiftRight(v21);
//	std::cout << "C(X,10,20):" << std::endl;;
//	for (int i = 0; i < v21.size(); i++)
//		std::cout << v21[i] << std::endl;
//
//
//	//D
//	std::vector<int> v22({ 10,20,30,40,50 });
//	rotateLeft(v22);
//	std::cout << "D(20,30,40,50,10):" << std::endl;;;
//	for (int i = 0; i < v22.size(); i++)
//		std::cout << v22[i] << std::endl;
//
//	//E
//	std::vector<int> v23({ 20,20,20,30,30,30 });
//	std::vector<int> v24({ 10,20,20,30,20,20 });
//	searchAdjacent(v23); 
//	searchAdjacent(v24); 
//
//	std::cout << "E(20,20,20,30,30,30): " ;
//	for (int i = 0; i < v23.size(); i++)
//		std::cout << v23[i] << ", ";
//
//	std::cout << std::endl << "E(10,20,20,30,20,20):";
//	for (int x : v24)
//	{
//		std::cout << x << ", ";
//	}
//	std::cout << std::endl;
//
//
//	//F
//	std::vector<char> fraseC({ 'L','O','I','R','O',' ','O','R','I','O','L' });
//	std::vector<char> fraseM({ 'L','O','I','R','O',' ','A','R','I','O','L' });
//	std::cout << "F (true): " << isPalindrome(fraseC) << std::endl;
//	std::cout << "F (false): " << isPalindrome(fraseM) << std::endl;
//		
//
//
//
//	system("pause");
//
//
//	return 0;
//}