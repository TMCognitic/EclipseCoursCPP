#include <iostream>
#include <limits>

using namespace std;

int main()
{
	cout << "Attention les tailles peuvent varier en fonction de l'environnement et du compilateur utilise" << endl;
	cout << "Size of char : " << sizeof(char) << endl;
	cout << "Range of values : " << (int)std::numeric_limits<char>::min() << " <-- 0 --> " << (int)std::numeric_limits<char>::max() << endl;
	cout << "Size of char : " << sizeof(wchar_t) << endl;
	cout << "Range of values : " << (unsigned int)std::numeric_limits<wchar_t>::min() << " <-- 0 --> " << (unsigned int)std::numeric_limits<wchar_t>::max() << endl;
	cout << "Size of char16_t : " << sizeof(char16_t) << endl;
	cout << "Range of values : " << (unsigned int)std::numeric_limits<char16_t>::min() << " <-- 0 --> " << (unsigned int)std::numeric_limits<char16_t>::max() << endl;
	cout << "Size of char32_t : " << sizeof(char32_t) << endl;
	cout << "Range of values : " << (unsigned int)std::numeric_limits<char32_t>::min() << " <-- 0 --> " << (unsigned int)std::numeric_limits<char32_t>::max() << endl;

	cout << endl;

	char c1 = 'A';
	cout << "valeur de c1 : " << c1 << endl;
	wchar_t c2 = L'A';
	cout << "valeur de c2 via cout : " << c2 << endl;
	wcout << "valeur de c2 via wcout : " << c2 << endl;
	char16_t c3 = u'A';
	cout << "valeur de c3 via cout : " << c3 << endl; //affichera 65 car la console n'interprete pas les char16_t
	wcout << "valeur de c3 via wcout : " << c3 << endl; //affichera 65 car la console n'interprete pas les char16_t
	char32_t c4 = U'A';
	cout << "valeur de c4 via cout : " << c4 << endl; //affichera 65 car la console n'interprete pas les char32_t
	wcout << "valeur de c4 via wcout : " << c4 << endl; //affichera 65 car la console n'interprete pas les char32_t

	// Multicharacter literals
	int c5 = 'ABCD'; //transforme en hexadécimal
		/*
			A à pour code ASCII 65 => 41 hex
			B à pour code ASCII 66 => 42
			C à pour code ASCII 67 => 43
			D à pour code ASCII 68 => 44
			La valeur calculée est donc 0x41424344 => ‭1 094 861 636‬ en décimal
		*/
		//<- est de type entier et
		cout << "valeur de c5 : " << c5 << endl;
	//réactive le warning à la compilation


	getchar();
	return 0;
}
