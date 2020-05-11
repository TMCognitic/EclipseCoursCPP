#pragma once
#include <string>
using namespace std;

class Personne
{
private:
	string _nom, _prenom;

	void SetNom(string);
	void SetPrenom(string);
public:
	Personne(const string& nom, const string& prenom);

	string GetNom();	
	string GetPrenom();	
	
};

