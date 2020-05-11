#include <iostream>
#include "PointersAndReferences.h"
using namespace std;


int main()
{
	cout << "Notion de pointeurs" << endl;
	float f = 5.0;
	float* ptr_f = nullptr;
	ptr_f = &f;

	cout << "valeur de f : " << f << endl;
	cout << "valeur de ptr_f : " << ptr_f << endl;
	cout << "valeur ciblee par ptr_f : " << *ptr_f << endl;


	cout << endl << "Notion de reference : " << endl;
	int x = 5;
	int& y = x;

	cout << "y est une reference vers x" << endl;
	cout << "Valeur de x : " << x << " et valeur de y : " << y << endl;
	cout << "y et x ont la meme adresse.." << endl;
	cout << "Adresse de x : " << &x << " et adresse de y : " << &y << endl;
	cout << "Modifier x revient a modifier x et vis et verca" << endl;
	x = 7;
	cout << "x = 7 -> " << "valeur de x : " << x << " et valeur de y : " << y << endl;
	y = 9;
	cout << "y = 9 -> " << "valeur de x : " << x << " et valeur de y : " << y << endl;

	Increment(x); //Utilisant le concept de référence
	cout << "Valeur incrementee de x : " << x << endl;
	Decrement(&y); //Utilisant le concept de pointeur
	cout << "Valeur decrementee de y : " << y << endl;

	int* ptr_x = &x;

	cout << "ceci fonctionne parfaitement : int& ref_ptrx = *ptr_x;" << endl;
	int& ref_ptrx = *ptr_x;
	cout << "Valeur de ref_ptrx : " << ref_ptrx << ", valeur ciblee par ptr_x : " << *ptr_x << " et valeur de x : " << x << endl;
	cout << "adresse de ref_ptrx : " << &ref_ptrx << ", adresse contenue dans ptr_x : " << ptr_x << " et adresse de x : " << &x << endl;

	getchar();
	return 0;

}
