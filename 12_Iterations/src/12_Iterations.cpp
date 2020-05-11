#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    int tab[]{ 0, 1, 2, 3, 4 };
	size_t sizeTab = sizeof(tab) / sizeof(int);

	//Boucle for classique
	for (size_t i = 0; i < sizeTab; i++)
	{
		cout << tab[i] << "\t";
	}
	cout << endl;

	for (int* tab_ptr = tab, *end = tab_ptr + sizeTab; tab_ptr < end; tab_ptr++)
	{
		cout << *tab_ptr << "\t";
	}
	cout << endl;

	//Boucle Ranged for // equivalent du foreach en C#
	for (int value : tab)
	{
		cout << value << "\t";
	}
	cout << endl;

	int* btab = begin(tab); //retourne le pointeur du premier élément
	int* etab = end(tab); //retourne l'adresse suivante du dernier élément

	for (int *start = btab; start < etab; start++)
	{
		cout << *start << "\t";
	}
	cout << endl;

	while (btab < etab)
	{
		cout << *btab << "\t";
		btab++;
	}
	cout << endl;

	btab = begin(tab);
	//#include <algorithm> (included in array)
	//Notons la présence de l'expression lambda en paramètre de la méthode
	for_each(btab, etab, [](int value) { cout << value << "\t"; });
	cout << endl;

	//Utilisation des iterateur
	//Même chose avec les vecteurs
	array<int, 5U> values{ 5, 6, 7, 8, 9 };
	//Iterateur simple
	for (array<int, 5U>::iterator p = values.begin(); p < values.end(); p++)
	{
		cout << *p << "\t";
	}
	cout << endl;

	//Iterateur inverse
	for (array<int, 5U>::reverse_iterator p = values.rbegin(); p < values.rend(); p++)
	{
		cout << *p << "\t";
	}
	cout << endl;
	//ou
	for (reverse_iterator<array<int, 5U>::iterator> p = values.rbegin(); p < values.rend(); p++)
	{
		cout << *p << "\t";
	}
	cout << endl;

	//utilisation de la méthode foreach
	for_each(values.begin(), values.end(), [](int value) { cout << value << "\t"; });
	cout << endl;

	for_each(values.rbegin(), values.rend(), [](int value) { cout << value << "\t"; });
	cout << endl;
}
