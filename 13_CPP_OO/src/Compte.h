#pragma once
#include <string>
#include "IBanker.h"
#include "NotifyHandler.h"
#include "Personne.h"
using namespace std;
class Compte : public NotifyHandler, public IBanker
{
private:
	//Champs
	string _numero;
	double _solde;
	Personne* _titulaire;

	//Accesseurs	
	void SetNumero(string);
	virtual void SetSolde(double) final; //final signifie que la méthode ne peut plus étre override
	void SetTitulaire(Personne* value);	
protected:
	//Constructeurs
	//Il n'y a pas de mot-cl� abstract en c++
	//Un moyen est de mettre les constructeurs au maximum en protected
	Compte(string numero, Personne* titulaire);
	Compte(string numero, Personne* titulaire, const double solde);

	//Methodes
	//Un autre moyen est de mettre un membre en virtuel pure (l'idéal est de faire les deux)
	virtual double CalculInteret() = 0;
	void Retrait(const double montant, const double ligneDeCredit);

public:
	//Opérateurs
	friend double operator+(Compte&, const double);
	friend double operator+(const double, Compte&);

	//Accesseurs
	virtual string GetNumero() final;	
	virtual double GetSolde() final;
	virtual Personne& GetTitulaire() final;	
	
	//Methodess
	virtual void AppliquerInteret() final;
	void Depot(double montant);
	virtual void Retrait(double montant);
};

