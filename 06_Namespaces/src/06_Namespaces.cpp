#include <iostream>

#include "Namespaces.h"

int main()
{
    //Sans le using
    std::cout << "Hello World!" << std::endl;
    using namespace std;
    //avec le using
    cout << "Hello World!" << endl;

    //Ce using n'importe que la variable Valeur et non pas tous le namspace
    //using MonEspaceDeNoms::Valeur;
    cout << MonEspaceDeNoms::Add(5, 7) << endl;
    cout << MonEspaceDeNoms::Valeur << endl;

    getchar();
    return 0;
}
