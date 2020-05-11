#pragma once

//en c++, une interface est une classe abstraite
class ICustomer
{
	virtual double GetSolde() = 0;

	virtual void Depot(double montant) = 0;
	virtual void Retrait(double montant) = 0;
};

