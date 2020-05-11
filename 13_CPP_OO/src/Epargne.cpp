#include "Epargne.h"



double Epargne::CalculInteret()
{
	return GetSolde() * 0.45;
}

Epargne::Epargne(string numero, Personne* titulaire)
	: Compte(numero, titulaire)
{
}

Epargne::Epargne(string numero, Personne* titulaire, const double solde)
	: Compte(numero, titulaire, solde)
{
}

Epargne::~Epargne()
{

}
