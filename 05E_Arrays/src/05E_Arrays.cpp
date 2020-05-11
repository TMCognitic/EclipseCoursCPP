#include <iostream>
#include <array>
#include <vector>
#include <map>
using namespace std;

int main()
{
    //C-Style Arrays
    int tab[]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int tab2[10];

    //La définition de size_t est un unsigned int
    int tabSize = sizeof(tab) / sizeof(int);
    cout << "Taile de tab : " << tabSize << endl << endl;

    int tab2Size = sizeof(tab2) / sizeof(int);

    //spécifier les valeurs par l'index
    for (int i = 0, value = 20; i < tab2Size; i++, value++)
    {
        tab2[i] = value;
    }

    //lire les valeurs par l'index
    for (int i = 0, value = 20; i < tab2Size; i++, value++)
    {
        cout << tab2[i] << endl;
    }

    cout << endl;

    //spécifier les valeurs par pointeur
    for (int *ptr_tab2 = tab2, *end = tab2 + 10, value = 30; ptr_tab2 < end; ptr_tab2++, value++)
    {
        *ptr_tab2 = value;
    }

    //lire les valeurs par pointeur
    for (int* ptr_tab2 = tab2, *end = tab2 + 10; ptr_tab2 < end; ptr_tab2++)
    {
        cout << "valeur a l'adresse " << ptr_tab2 << " : " << *ptr_tab2 << endl;
    }

    cout << endl;

    //Attention ceci est permis
    int* ptr_tab = &tab2[4];

    cout << "affiche le 7eme element du tableau : " << *(ptr_tab + 2) << endl;
    cout << "affiche le 3eme element du tableau : " << ptr_tab[-2] << endl; //Déférencement

    cout << endl;

    //Modern C++ Array
    //add #include <array>
    //tableau initisalisé
    array<int, 10> values { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //tableau non initisalisé
    array<int, 10> values2;

    for (size_t i = 0, value = 40; i < values2.size(); i++, value++)
    {
        values2[i] = value;
    }

    for (size_t i = 0; i < values2.size(); i++)
    {
        cout << values2[i] << endl;
    }

    cout << endl;
    //Equivalent d'une boucle foreach en C# -- Range-For
    for (const int& value : values)
    {
        cout << value << endl;
    }

    //Utilisation des Vector
    vector<int> vector;
    //Ajout d'éléments
    vector.push_back(7);
    vector.push_back(5);
    vector.push_back(7);
    vector.push_back(9);

    //Suppression d'éléments
    vector.erase(vector.begin());
    vector.erase(vector.begin() + 1);

    cout << endl;
    //On peut utiliser l'indexeur
    cout << vector[0] << endl;
    cout << endl;

    for (const int& value : vector)
    {
        cout << value << endl;
    }


    //Map // Dictionnary Paire de clé valeur.
    map<int, int> aMap;
    aMap.insert(make_pair(5, 17));
    aMap.insert(make_pair(15, 27));

    cout << endl;
    cout << aMap[5] << endl;
    cout << aMap[15] << endl;

    aMap.erase(aMap.find(5));


    for (const pair<int, int>& value : aMap)
    {
        cout << value.first << " : " << value.second << endl;
    }

    getchar();
    return 0;
}
