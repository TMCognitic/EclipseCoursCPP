#include <iostream>

using namespace std;

int Add(int, int);

int main(int parameterCount, char** parameter)
{
	cout << "5 + 4 = " << Add(5, 4) << endl;
	getchar();
}

int Add(int a, int b)
{
	return a + b;
}
