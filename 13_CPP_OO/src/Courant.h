#pragma once
#include "Compte.h"

using namespace std;

class Courant : public Compte
{
private :
	double _ligneDeCredit;
protected:
	double CalculInteret() override;

public:
	virtual ~Courant();
	Courant(string numero, Personne* titulaire);
	Courant(string numero, Personne* titulaire, const double solde);
	Courant(string numero, const double ligneDeCredit, Personne* titulaire);

	double GetLigneDeCredit();
	void SetLigneDeCredit(double);

	void Retrait(double montant) override;
};

