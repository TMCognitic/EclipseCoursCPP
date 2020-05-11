#include <iostream>
#include <limits>

using namespace std;

int main()
{
	cout << "Attention les tailles peuvent varier en fonction de l'environnement et du compilateur utilise" << endl;
	cout << "Size of short : " << sizeof(short) << endl;
	cout << "Range of values : " << std::numeric_limits<short>::min() << " <-- 0  --> " << std::numeric_limits<short>::max() << endl;
	cout << "Size of int : " << sizeof(int) << endl;
	cout << "Range of values : " << std::numeric_limits<int>::min() << " <-- 0  --> " << std::numeric_limits<int>::max() << endl;
	cout << "Size of unsigned int : " << sizeof(unsigned) << endl;
	cout << "Range of values : " << std::numeric_limits<unsigned>::min() << " --> " << std::numeric_limits<unsigned>::max() << endl;
	cout << "Size of long : " << sizeof(long) << endl;
	cout << "Range of values : " << std::numeric_limits<long>::min() << " <-- 0 --> " << std::numeric_limits<long>::max() << endl;
	cout << "Size of unsigned long : " << sizeof(unsigned long) << endl;
	cout << "Range of values : " << std::numeric_limits<unsigned long>::min() << " --> " << std::numeric_limits<unsigned long>::max() << endl;
	cout << "Size of long long : " << sizeof(long long) << endl;
	cout << "Range of values : " << std::numeric_limits<long long>::min() << " <-- 0 --> " << std::numeric_limits<long long>::max() << endl;
	cout << "Size of unsigned long long : " << sizeof(unsigned long long) << endl;
	cout << "Range of values : " << std::numeric_limits<unsigned long long>::min() << " <-- 0 --> " << std::numeric_limits<unsigned long long>::max() << endl;
	// Les autres peuvent être trouvés dans limits

	//désactive le warning à la compilation
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
	int x; //Variable non initialisée <-- warning C4101: 'x' : variable locale non référencée
	//cout << x << endl; //<-- Erreur
	//réactive le warning à la compilation
#pragma GCC diagnostic pop

	int n{}; // Variable initialisée par défaut
	cout << n << endl;
	bool b{};
	cout << b << endl;

	getchar();
	return 0;
}
