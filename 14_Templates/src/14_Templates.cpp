//============================================================================
// Name        : 14_Templates.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Templates.h"

//Utilisation de l'existant
pair<int, int> GetSumAndProduct(int, int);
tuple<int, int, int> GetSumProductAverage(int, int, int);

//Declaration du type trio
template<typename T1, typename T2, typename T3>
struct trio
{
	T1 first;
	T2 second;
	T3 third;

	trio(const T1& first, const T2& second, const T3& third)
		: first(first), second(second), third(third)
	{
	}
};

//Utilisation du type trio
trio<int, int, int> GetTrio(int, int, int);

//template method
template<typename T>
vector<T> Where(const vector<T>&, function<bool(const T&)>);

//Template Specialization
//Important : Review Template Specialization

//Variadic Template
template<typename T>
T sum(T t) {return t;}

//En c++ 11
//template <typename T, typename... U>
//auto sum(const T& t, const U&... u) -> decltype(t + sum(u...))
//{
//    return t + sum(u...); //Attention il est possible que le decltype n'apprécie pas la récursivité
//}

//Depuis c++ 14, le type est déduit automatiquement
template <typename T, typename... P>
auto sum(const T& t, const P&... p){
    return t + sum(p...);
}

//Metaprogramming template
template<int n> struct Factorielle
{
	enum { value = n * Factorielle<n-1>::value };
};

//Template specialization
template<> struct Factorielle<0>
{
	enum { value = 1 };
};

int main() {
	//Consommation
	pair<int, int> sumAndProduct = GetSumAndProduct(4, 5);
	cout << "Somme : " << sumAndProduct.first << " - Produit : " << sumAndProduct.second << endl;
	//ou
	cout << "Somme : " << get<0>(sumAndProduct) << " - Produit : " << get<1>(sumAndProduct) << endl;

	tuple<int, int, int> sumProductAverage = GetSumProductAverage(4, 5, 6);
	cout << "Somme : " << get<0>(sumProductAverage) << " - Produit : " << get<1>(sumProductAverage) <<
		 " - Moyenne : " << get<2>(sumProductAverage) << endl;

	//Consommation du type trio
	//Attention celui- ne supporte pas la récupération par get
	trio<int, int, int> trio = GetTrio(4, 5, 6);

	cout << "Somme : " << trio.first << " - Produit : " << trio.second <<
			 " - Moyenne : " << trio.third << endl;


	//Consommation de la méthode Where
	vector<int> ints{ 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> result = Where<int>(ints, [](int x) { return x % 2 == 0; });

	for_each(result.begin(), result.end(), [](int value) { cout << value << endl; });

	//Consommation du variadic template
	auto resultSum = sum(10.5, 2, 3.2f, 4);
	cout << (double)resultSum << std::endl;

	//Consommation du Metaprogramming template
	cout << Factorielle<4>::value << endl;
	return 0;
}

pair<int, int> GetSumAndProduct(int a, int b)
{
	return pair<int, int>(a + b, a * b);
}

tuple<int, int, int> GetSumProductAverage(int a, int b, int c)
{
	return tuple<int, int, int>{ a + b + c, a * b * c, (a + b + c) / 3 };
}

trio<int, int, int> GetTrio(int a, int b, int c)
{
	return trio<int, int, int>(a + b + c, a * b * c, (a + b + c) / 3);
}

//template method implementation
template<typename T>
vector<T> Where(const vector<T>& elts, std::function<bool(const T&)> predicate)
{
	vector<T> result;

	for (T value : elts)
	{
		if(predicate(value))
			result.push_back(value);
	}

	return result;
}


