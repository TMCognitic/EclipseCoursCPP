#pragma once

#ifndef _Functions_H
#define _Functions_H

namespace Functions
{
	//On évite de déclarer des variables dans un namespace sauf si ce sont des constances
	const int Valeur = 42;

	inline int Addition(const int a, const int b)
	{
		return a + b;
	}

	int Add(int a, int b);
}

#endif
