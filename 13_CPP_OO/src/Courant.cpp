#include "Courant.h"

Courant::Courant(string numero, Personne* titulaire)
	: Compte(numero, titulaire)
{
	_ligneDeCredit = 0;
}

Courant::Courant(string numero, Personne* titulaire, const double solde)
	: Compte(numero, titulaire, solde)
{
	_ligneDeCredit = 0;
}

Courant::Courant(string numero, const double ligneDeCredit, Personne* titulaire)
	: Compte(numero, titulaire)
{
	SetLigneDeCredit(ligneDeCredit);
}

Courant::~Courant()
{

}

double Courant::GetLigneDeCredit()
{
	return _ligneDeCredit;
}

void Courant::SetLigneDeCredit(double value)
{
	if (value < 0)
	{
		return;
	}

	_ligneDeCredit = value;
}

double Courant::CalculInteret()
{
	return GetSolde() * ((GetSolde() < 0) ? .0975 : .03);
}

void Courant::Retrait(double montant)
{
	const double oldSolde = GetSolde();
	Compte::Retrait(montant, GetLigneDeCredit());

	if (oldSolde >= 0.0 && GetSolde() < 0)
		Raise(GetNumero());
}
