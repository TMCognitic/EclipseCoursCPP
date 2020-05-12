#include "Compte.h"
#include "SoldeInsuffisantException.h"

double operator+(Compte& courant, const double d)
{
	return ((d < 0.0) ? .0 : d) + ((courant.GetSolde() < 0.0) ? .0 : courant.GetSolde());
}

double operator+(const double d, Compte& courant)
{
	return courant + d;
}

Compte::Compte(string numero, Personne* titulaire)
{
	SetNumero(numero);
	SetTitulaire(titulaire);
}

Compte::Compte(string numero, Personne* titulaire, const double solde)
	: Compte(numero, titulaire)
{
	SetSolde(solde);
}

Compte::~Compte()
{

}

string Compte::GetNumero()
{
	return _numero;
}

void Compte::SetNumero(string value)
{
	_numero = value;
}

double Compte::GetSolde()
{
	return this->_solde;
}

void Compte::SetSolde(double value)
{
	_solde = value;
}

Personne& Compte::GetTitulaire()
{
	return *_titulaire;
}

void Compte::SetTitulaire(Personne* value)
{
	_titulaire = value;
}

void Compte::AppliquerInteret()
{
	_solde += CalculInteret();
}

void Compte::Depot(double montant)
{
	if (montant <= 0)
		return;

	SetSolde(GetSolde() + montant);
}

void Compte::Retrait(const double montant, const double ligneDeCredit)
{
	if (montant <= 0)
		return;

	if (GetSolde() - montant < -ligneDeCredit)
		throw soldeInsuffisantException;

	SetSolde(GetSolde() - montant);
}

void Compte::Retrait(double montant)
{
	Retrait(montant, 0.0);
}
