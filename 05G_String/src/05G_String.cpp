#include <iostream>

using namespace std;


int main()
{
	//C-Style String
	const char* cString = "Hello";
	//En mémoire elle se termine par le caractère '\0'
	int temp = sizeof(cString) / sizeof(*cString);
	cout << temp << endl;

	size_t len = 0;
	for (size_t i = 0; *(cString + i) != '\0'; i++)
	{
		len++;
	}

	cout << "Longueur de cString : " << len << endl;

	for (size_t i = 0; i < len; i++)
	{
		cout << (char)*(cString + i);
	}
	cout << endl;
	//ou
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-security"
	printf(cString);
#pragma GCC diagnostic pop

	cout << endl;

	//le type string
	string s = "Hello";
	cout << "Valeur de s : " << s << endl;
	cout << "Longueur de s : " << s.length() << " - " << s.size() * sizeof(char) << " octests." << endl;
	cout << "Sous chaine de s : " << s.substr(1, 3) << endl;
	s += " world!";
	s[0] = 'W';
	cout << s << endl;

	//le type wstring
	wstring ws = L"Hello";
	wcout << "Valeur de ws : " << ws << endl;
	cout << "Longueur de ws : " << ws.length() << " - " << ws.size() * sizeof(wchar_t) << " octests." << endl;
	wcout << "Sous chaine de ws : " << ws.substr(3, 3) << endl;


	cout << endl << "utilisation du suffixe s" << endl;
	auto s1 = "Hello"; //<- char *
	auto s2 = "Hello"s; //<- string en utilisant le suffixe s

	cout << "type de s1 : " << typeid(s1).name() << endl;
	cout << "type de s2 : " << typeid(s2).name() << endl;

	getchar();
	return 0;
}
