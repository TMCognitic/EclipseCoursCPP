#pragma once
#include "Compte.h"

class Epargne : public Compte
{
protected:
	double CalculInteret() override;

public:
	virtual ~Epargne();
	Epargne(string numero, Personne* titulaire);
	Epargne(string numero, Personne* titulaire, const double solde);
};

