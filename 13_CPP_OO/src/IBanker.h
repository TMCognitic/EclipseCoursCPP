#pragma once

#include <string>
#include "ICustomer.h"
#include "Personne.h"

using namespace std;

class IBanker : public ICustomer
{
	virtual string GetNumero() = 0;
	virtual Personne& GetTitulaire() = 0;
	virtual void AppliquerInteret() = 0;
};

