#pragma once
#include <map>
#include <iostream>
#include <string>
#include "Compte.h"

using namespace std;

class Banque
{
private:
	string _nom;
	map<string, Compte*> _comptes{};

	//Methodes
	const void OnNotification(const string& numero);
	function<void(const string&)> _onNotification = [this](const string& numero) { this->OnNotification(numero); };
public:
	Compte* operator[](const string& numero);
	~Banque();

	//Courant* GetCompte(const string& numero);
	void Ajouter(Compte* compte);
	void Supprimer(string numero);

	double AvoirDesComptes(Personne* titulaire);
};

