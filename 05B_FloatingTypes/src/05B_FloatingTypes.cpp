#include <iostream>
#include <float.h>

using namespace std;


int main()
{
	cout << "Attention les tailles peuvent varier en fonction de l'environnement et du compilateur utilise" << endl;
	cout << "Size of float : " << sizeof(float) << endl;
	cout << "Range of values : " << FLT_MIN << " <-- 0 --> " << FLT_MAX << endl;
	cout << "Size of double : " << sizeof(double) << endl;
	cout << "Range of values : " << DBL_MIN << " <-- 0 --> " << DBL_MAX << endl;
	cout << "Size of long double : " << sizeof(long double) << endl;
	cout << "Range of values : " << LDBL_MIN << " <-- 0 --> " << LDBL_MAX << endl;

	cout << endl;

	float f = 1.2f;
	cout << "value of f : " << f << endl;

	getchar();
	return 0;
}
