#include <iostream>

using namespace std;


int main()
{
	cout << "Attention les tailles peuvent varier en fonction de l'environnement et du compilateur utilise" << endl;
	cout << "Size of bool : " << sizeof(bool) << endl;
	cout << "Range of values : " << false << "(false) or " << true << "(true)" << endl;

	bool b{};
	cout << (b ? "true" : "false") << endl;

	int x = 5, y = 7;

	cout << endl << "Test logique" << endl;
	bool result = x < y; // <, <=, >, >=, ==, !=
	cout << "< (plus petit) " << (result ? "true" : "false") << endl;
	result = x <= y;
	cout << "<= (plus petit ou egal) " << (result ? "true" : "false") << endl;
	result = x > y;
	cout << "> (plus grand) " << (result ? "true" : "false") << endl;
	result = x >= y;
	cout << "> (plus grand ou egal) " << (result ? "true" : "false") << endl;
	result = x == y;
	cout << "== (egal) " << (result ? "true" : "false") << endl;
	result = x != y;
	cout << "!= (different) " << (result ? "true" : "false") << endl;
	result = !result;
	cout << "! (not)" << (result ? "true" : "false") << endl;

	cout << endl << "Attention" << endl;
	bool boolean = 0;
	cout << "bool boolean = 0 : " << boolean << endl;

	boolean = 5; //warning C4305: '=' : troncation de 'int' à 'bool'
	cout << "bool boolean = 5 : " << boolean << endl;

	//interet du 0 false et le reste est vrai
	const char* character = "Morre Thierry";
	while (*character)
	{
		putchar(*character);
		character++;
	}

	getchar();
	return 0;
}
