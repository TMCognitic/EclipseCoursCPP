#include "Banque.h"

const void Banque::OnNotification(const string& numero)
{
	cout << "Le compte " << numero << " vient de passe en negatif..." << endl;
}

Compte* Banque::operator[](const string& numero)
{
	auto it = _comptes.find(numero);

	if (it == _comptes.end())
		return nullptr;

	return _comptes[numero];
}

Banque::~Banque()
{
	_comptes.clear();
}

//Remplac� par la surcharge de l'op�rateur d'index
//Courant* Banque::GetCompte(const string& numero)
//{
//	auto it = _comptes.find(numero);
//
//	if (it == _comptes.end())
//		return nullptr;
//
//	return _comptes[numero];
//}

void Banque::Ajouter(Compte* compte)
{	
	_comptes.emplace(compte->GetNumero(), compte);
	compte->Register(_onNotification);
}

void Banque::Supprimer(string numero)
{
	auto it = _comptes.find(numero);

	if (it != _comptes.end())
	{
		Compte* compte = _comptes[numero];
		compte->Unregister(_onNotification);
		_comptes.erase(it);
	}
}

double Banque::AvoirDesComptes(Personne* titulaire)
{
	double total = 0.0;
	for (pair<string, Compte*> pair : _comptes)
	{
		if (pair.second != nullptr && &pair.second->GetTitulaire() == titulaire)
		{
			total = total + *(pair.second);
		}
	}

	return total;
}
