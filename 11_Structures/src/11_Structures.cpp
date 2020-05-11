#include <iostream>
using namespace std;

namespace Cartes
{
    enum class Couleur {
        Coeur,
        Carreau,
        Pique,
        Trefle
    };

    enum class Valeur
    {
        Deux = 2,
        Trois,
        Quatre,
        Cinq,
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

    //Un type de structure est un type composite défini par l'utilisateur.
    //Il est composé de champs ou de membres qui peuvent avoir différents types.
    //En C++, une structure est identique à une classe sauf que ses membres sont publics par défaut.
    //En règle générale, on utilise pas d'héritage avec les structures et elle ne contiennent généralement que des champs.
    struct Carte
    {
        Couleur couleur;
        Valeur valeur;

        void Affiche()
        {
            const char* couleur = nullptr;
            const char* valeur = nullptr;

            switch (this->couleur)
            {
            case Couleur::Coeur:
                couleur = "Coeur";
                break; //Attention en C++ le break est facultatif
            case Couleur::Carreau:
                couleur = "Carreau";
                break;
            case Couleur::Pique:
                couleur = "Pique";
                break;
            case Couleur::Trefle:
                couleur = "Trefle";
                break;
            }

            switch (this->valeur)
            {
            case Valeur::Deux:
                valeur = "Deux";
                break;
            case Valeur::Trois:
                valeur = "Trois";
                break;
            case Valeur::Quatre:
                valeur = "Quatre";
                break;
            case Valeur::Cinq:
                valeur = "Cinq";
                break;
            case Valeur::Six:
                valeur = "Six";
                break;
            case Valeur::Sept:
                valeur = "Sept";
                break;
            case Valeur::Huit:
                valeur = "Huit";
                break;
            case Valeur::Neuf:
                valeur = "Neuf";
                break;
            case Valeur::Dix:
                valeur = "Dix";
                break;
            case Valeur::Valet:
                valeur = "Valet";
                break;
            case Valeur::Dame:
                valeur = "Dame";
                break;
            case Valeur::Roi:
                valeur = "Roi";
                break;
            case Valeur::As:
                valeur = "As";
                break;
            }

            cout << valeur << " de " << couleur << endl;
        }
    };

    void Affiche(Carte carte)
    {
        const char* couleur = nullptr;
        const char* valeur = nullptr;

        switch (carte.couleur)
        {
            case Couleur::Coeur:
                couleur = "Coeur";
                break;
            case Couleur::Carreau:
                couleur = "Carreau";
                break;
            case Couleur::Pique:
                couleur = "Pique";
                break;
            case Couleur::Trefle:
                couleur = "Trefle";
                break;
        }

        switch (carte.valeur)
        {
            case Valeur::Deux:
                valeur = "Deux";
                break;
            case Valeur::Trois:
                valeur = "Trois";
                break;
            case Valeur::Quatre:
                valeur = "Quatre";
                break;
            case Valeur::Cinq:
                valeur = "Cinq";
                break;
            case Valeur::Six:
                valeur = "Six";
                break;
            case Valeur::Sept:
                valeur = "Sept";
                break;
            case Valeur::Huit:
                valeur = "Huit";
                break;
            case Valeur::Neuf:
                valeur = "Neuf";
                break;
            case Valeur::Dix:
                valeur = "Dix";
                break;
            case Valeur::Valet:
                valeur = "Valet";
                break;
            case Valeur::Dame:
                valeur = "Dame";
                break;
            case Valeur::Roi:
                valeur = "Roi";
                break;
            case Valeur::As:
                valeur = "As";
                break;
        }

        cout << valeur << " de " << couleur << endl;
    }
}

int main()
{
    using namespace Cartes;
    //Cartes sur la pile
    Carte carte1{ Couleur::Coeur, Valeur::As };
    Carte carte2;
    carte2.couleur = Couleur::Pique;
    carte2.valeur = Valeur::Dame;

    Affiche(carte1);
    carte1.Affiche();
    Affiche(carte2);
    carte2.Affiche();

    cout << "Taille d'une carte : " << sizeof(Carte) << endl;

    //Carte sur le tas
    Carte* carte3 = new Carte();
    carte3->couleur = Couleur::Trefle;
    carte3->valeur = Valeur::Cinq;

    carte3->Affiche();
    Affiche(*carte3);

    cout << "Taille d'un pointeur sur carte : " << sizeof(carte3) << endl;
    //Nettoyage
    delete carte3;

    getchar();
    return 0;
}

