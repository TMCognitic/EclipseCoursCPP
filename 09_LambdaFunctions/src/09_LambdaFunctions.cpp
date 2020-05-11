#include <iostream>
#include "time.h"
#include <functional>

using namespace std;

int main()
{
    //En C++ 11 et versions ultérieures, une expression lambda, souvent appelée lambda,
    //est un moyen pratique de définir un objet de fonction anonyme

    //une expression lambda est définie comme suit
    //-1- --------2--------- ----3---- ----4---- ----5---- -------------------6-------------------
    //[ ] (float a, float b) [mutable] [throw()] [-> bool] { return (std::abs(a) < std::abs(b)); }

    /*
    1. clause de capture (également appelée lambda-introducteur dans la C++ spécification.)
       [] indique que le corps de l’expression lambda n’accède à aucune variable dans la portée englobante
       [=] capture toute les variables locales par valeur
       [&] capture toute les variables locales par référence
       [&, x] capture toute les variables locales par référence sauf x par valeur
       [&y, x] capture y par référence et x par valeur
       quelques exemples :
       [&, i]{};      // OK
       [&, &i]{};     // ERREUR: la référence est par défaut et on passe i par référence
       [=, this]{};   // ERREUR: this quand = est par défaut -- Nécessite la couche OO
       [=, *this]{ }; // OK.                                 -- Nécessite la couche OO
       [i, i]{};      // ERREUR: i est répété
    2. liste de paramètres Facultatif. (Également appelé déclarateur lambda)
       Si aucun paramètre mettre ().
    3. spécification mutable Facultatif.
       En règle générale, l’opérateur d’appel de fonction d’une expression lambda est const par valeur,
       mais l’utilisation du mot clé mutable annule cette opération.
       Elle ne produit pas de membres de données mutables.
       La spécification "mutable" permet au corps d’une expression lambda de modifier les variables capturées par valeur
    4. spécification d’exception Facultatif.
       Vous pouvez utiliser la spécification d’exception.
       - noexcept, noexcept(true) ou throw() signifient que l'expression ne lève pas d'exception (depuis c++ 14 il est recommendé d'utiliser noexcept)
       - noexcept(false), throw(...) ou aucune spécification signifient que la fonction peut lever une exception de tout type.
       - throw(type) signifie que la fonction peut lever une exception de type type.
         en c++ 14, le compilateur accepte la syntaxe, mais l’interprète comme noexcept(false).
         en c++ 17, le compilateur émet un avertissement C5040.
    5. type de retour de fin Facultatif.
       En effet, Le type de retour d’une expression lambda est déduit automatiquement
    6. corps lambda.
       Le corps lambda (Compound-Statement dans la syntaxe standard) d’une expression lambda peut contenir tout ce que le corps
       d’une méthode ou d’une fonction ordinaire peut contenir.
       Le corps d’une fonction ordinaire et d’une expression lambda peut accéder aux types de variables suivants :
       -- Variables capturées dans la portée englobante, comme décrit précédemment.
       -- Parameters
       -- Variables déclarées localement
       -- Membres de données de classe, lorsqu' ils sont déclarés dans une classe et qu’ils sont capturés
       -- Toute variable ayant une durée de stockage statique (par exemple, les variables globales)
    */

    int y = 5;

    function<int(int)> LambdaFunction = [](int x) { return x * 10; };
    cout << "Valeur de retour de LambdaFunction : " << LambdaFunction(y) << endl;

    function<int(int)> LambdaFunction2 = [y](int x) { return x * y; };
    cout << "Valeur de retour de LambdaFunction2 : " << LambdaFunction2(20) << endl;
    y = 100;
    cout << "Valeur de retour de LambdaFunction2 avec y = 100 : " << LambdaFunction2(30) << endl; //retourne 150
    //en effet la valeur de y est définie au moment de la déclaration de l'expression
    //donc pour LambdaFunction2 y a toujours pour valeur 5;

    //La déclaration suivant n'est pas valide car y est capturée en lecture seule (par défaut utilisation de const)
    //auto LambdaFunction3 = [y](int x) { y++; return x * y; };
    y = 5; //remise de la valeur initiale de y

    function<int(int)> LambdaFunction4 = [y](int x) mutable { y++; return x * y; };
    cout << "Valeur de retour de LambdaFunction4 : " << LambdaFunction4(30) << endl;
    cout << "Valeur de y : " << y << endl; //mutable n'a pas d'impacte du la variable d'origine

    function<int(int)> LambdaFunction5 = [&y](int x) { y++; return x * y; };
    cout << "Valeur de retour de LambdaFunction5 : " << LambdaFunction5(40) << endl;
    cout << "Valeur de y : " << y << endl; // affiche 6, car y a été capturée par référence

    //En C++14, on peut introduire et initialiser des variables dans la clause de capture,
    //sans qu'il ne soit nécessaire que ces variables existent dans la portée englobante de la fonction lambda.
    //L'initialisation peut être exprimée comme n'importe quelle expression arbitraire ;
    //le type de la nouvelle variable est déduit du type produit par l'expression.
    srand((unsigned)time(NULL));
    function<int(int)> LambdaFunction6 = [z = rand() % 97](int x) {
        cout << "Type de z : " << typeid(z).name() << " et valeur de z : " << z << endl;
        return z * x;
    };
    //En règle générale, et pour des raisons de lisibilité,
    //une expression lambda ne contient pas plus de 3 instructions. au delà --> Méthode
    cout << "Valeur de retour de LambdaFunction6 : " << LambdaFunction6(50) << endl;

    getchar();
    return 0;
}
