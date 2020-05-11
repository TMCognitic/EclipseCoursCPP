#include <iostream>
#include <vector>
using namespace std;


int main()
{
    //Rappel il n'y a pas de Grabage Collector en c++

    string s("Hello"); //Stocké dans la pile (stack)
    //Le nettoyage est automatique dès que l'on sort du scope courant

    //la taille du stack est limitée
    string* s_ptr = new string("Hello"); //l'utilisation de l'opérateur new implique la création d'un pointeur dans le Tas (heap)
    delete s_ptr; //Le nettoyage doit être fait manuellement par l'utilisation de l'opérateur delete

    size_t tabSize = 10;
    int* tab_ptr = new int[tabSize];

    //Remplissage par pointeur
    for (size_t i = 0; i < tabSize; i++)
    {
        *(tab_ptr + i) = i;
    }

    //Lecture par pointeur
    for (size_t i = 0; i < tabSize; i++)
    {
        cout << *(tab_ptr + i) << endl;
    }

    //delete tab_ptr; //est un erreur courante, mais elle ne supprimera de la mémoire que le premier élément du tableau;
    delete[] tab_ptr; //ceci est la bonne syntaxe pour supprimer un tableau

    getchar();
    return 0;
}
