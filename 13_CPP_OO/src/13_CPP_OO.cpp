#include <iostream>
#include "Banque.h"
#include "Courant.h"
#include "Epargne.h"
#include "Personne.h"

int main()
{
    Banque& banque = *(new Banque());

    Personne* p = new Personne("Doe"s, "John"s);
    Courant* c1 = new Courant("1234"s, 500, p);
    Epargne* c2 = new Epargne("1235"s, p);

    banque.Ajouter(c1);
    banque.Ajouter(c2);

    banque["1234"s]->Depot(300);
    banque["1235"s]->Depot(300);
    banque["1234"s]->Retrait(500);

    try
    {
        banque["1234"s]->Retrait(500);
    }
    catch (const std::exception& ex)
    {
        cout << ex.what() << endl;
    }

    banque["1235"s]->AppliquerInteret();
    banque["1234"s]->AppliquerInteret();

    cout << "Solde du compte 1234 : " << banque["1234"s]->GetSolde() << endl;
    cout << "Avoir des comptes de " << p->GetNom() << " " << p->GetPrenom() << " : " << banque.AvoirDesComptes(p) << endl;

    delete p;
    delete c1;
    delete c2;

    Banque *b = &banque;
    delete b;

    getchar();
    return 0;
}
