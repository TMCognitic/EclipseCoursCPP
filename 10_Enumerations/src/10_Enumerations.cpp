#include <iostream>
using namespace std;

namespace Cards_NonScoped
{
    enum Couleur {
        Coeur, //recoit la valeur 0 par défaut
        Carreau,  //recoit la valeur 1 par défaut
        Pique,  //recoit la valeur 2 par défaut
        Trefle //recoit la valeur 3 par défaut
    };

    enum Valeur
    {
        Deux = 2,
        Trois, //recoit la valeur 3 par défaut
        Quarte, //recoit la valeur 4 par défaut
        Cinq, //...
        Six,
        Sept,
        Huit,
        Neuf,
        Dix,
        Valet,
        Dame,
        Roi,
        As
    };

    void Procedure()
    {
        //Dans lutilisatation d'une enume classique, l'enum Couleur est équivalente à la sémentique suivante
        //static const int Coeur = 0;
        //static const int Carreau = 1;
        //static const int Pique = 2;
        //static const int Trefle = 3;
        Couleur couleur = Coeur; // Ce qui explique de l'enumeration est visible sans devoir spécifier le type conteneur

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
        int value = couleur; // et la conversion implicite en entier est possible
#pragma GCC diagnostic pop

        cout << "Valeur de couleur : " << couleur << endl;
        couleur = (Couleur)3;
        if (couleur == Trefle)
        {
            cout << "La couleur est Trefle!" << endl;
        }
    }
}

namespace Cards_Scoped
{
    enum class Couleur {
        Coeur, //recoit la valeur 0 par défaut
        Carreau,  //recoit la valeur 1 par défaut
        Pique,  //recoit la valeur 2 par défaut
        Trefle //recoit la valeur 3 par défaut
    };

    enum class Valeur : short //les constantes seront de type short
    {
        Deux = 2,
        Trois, //recoit la valeur 3 par défaut
        Quarte, //recoit la valeur 4 par défaut
        Cinq, //...
        Six,
        Sept,
        Huit,
        Neuf,
        Dix,
        Valet,
        Dame,
        Roi,
        As
    };

    void Procedure()
    {
        Couleur couleur = Couleur::Coeur; // L'énumeration doit être utilisée avec le type de l'énumération

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
        int value = (int)couleur; // et la conversion implicite en entier est impossible
#pragma GCC diagnostic pop

        cout << "Valeur de couleur : " << (int)couleur << endl;
        couleur = (Couleur)2;
        if (couleur == Couleur::Pique)
        {
            cout << "La couleur est Pique!" << endl;
        }
    }
}

int main()
{
    Cards_NonScoped::Procedure();
    cout << endl;
    Cards_Scoped::Procedure();

    getchar();
    return 0;
}
