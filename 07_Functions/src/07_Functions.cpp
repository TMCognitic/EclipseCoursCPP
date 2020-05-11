#include <iostream>
using namespace std;
#include "Functions.h"

//Déclaration d'une procédure
void Procedure(int&);

//Déclaration d'une fonction
int Fonction(const int, const int);
int Fonction2(const int, const int); //avec syntaxte alternative d'implémentation
int Fonction(string s);

//Déclaration d'une fonction inline
inline int FonctionInline(const int, const int);

//La méthode main est le point d'entrée de l'application
//Celle-ci peut recevoir deux variables
//la première est le nombre d'arguments passés à l'appel du programme
//La seconde est un pointeur sur ce table d'arguement
int main(const int argsCount, const char* args[])
{
    //a savoir que le premier argument est toujours le nom du programme
    cout << "Nombre d'argument(s) : " << argsCount << endl;
    cout << "Premier argument : " << args[0] << endl;

    int x = 8, y = 4;

    Procedure(y);
    cout << "Valeur de y : " << y << endl;
    Procedure(x);
    cout << "Valeur de x : " << x << endl;
    cout << "Valeur de retour de Fonction(x, y) : " << Fonction(x, y) << endl;
    cout << "Valeur de retour de Fonction2(x, y) : " << Fonction2(x, y) << endl;

    //Au moment de la compilation le compilateur remplacera l'appel de la fonction par le code de celle-ci
    //Permettant de gagner en maintenabilité, en réutilisation et en performence
    //a utiliser avec sagesse pour de petit bout de codes répétififs
    cout << "Valeur de retour de FonctionInline(x, y) : " << FonctionInline(x, y) << endl;
    //après compilation ce sera équivalent à si j'avais été le code suivant
    //cout << "Valeur de retour de FonctionInline(x, y) : " << x + y << endl;

    string s = "Hello"s;
    cout << Fonction(s) << endl;
    cout << s << endl;

    //Utilisation de Fonction depuis un namespace
    cout << "Valeur de retour de Functions::Add(5,7) : " << Functions::Add(5, 7) << endl;
    using namespace Functions;
    cout << "Valeur de retour de Functions::Addition(5,7) : " << Addition(5,7) << endl;

    getchar();
    return 0;
}

//Implémentation de la procédure
void Procedure(int& x)
{
    if (x > 5)
    {
        return; //Return sert à mettre fin à l'appel d'une méthode
    }

    x++;
}

//Implémentation de la fonction
//un paramètre défini const est un paramètre en lecture seule
int Fonction(const int a, const int b)
{
    return a * b; //dans le cas d'une fonction le return est obligatoire car il renvoit à l'appelant la valeur de retour de la fonction
}

int Fonction(string s) //Par valeur, s est une copie de la valeur de s de l'appelant
{
    s += "test"; //ne change pas la valeur de S de l'appelant
    s[0] = 'W'; //ne change pas la valeur de S de l'appelant
    return s.length();
}

//ou syntaxe alternative
auto Fonction2(const int a, const int b) -> int
{
    return a * b;
}

//Implémentation de la fonction inline
inline int FonctionInline(const int a, const int b)
{
    return a + b;
}
