#include "Personne.h"

string Personne::GetNom()
{
	return _nom;
}

void Personne::SetNom(string value)
{
	_nom = value;
}

string Personne::GetPrenom()
{
	return _prenom;
}

void Personne::SetPrenom(string value)
{
	_prenom = value;
}

Personne::Personne(const string& nom, const string& prenom)
{
	SetNom(nom);
	SetPrenom(prenom);
}
