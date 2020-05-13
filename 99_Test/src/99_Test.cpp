//============================================================================
// Name        : 99_Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int x = int(7);
	cout << x << endl;

	int* intPtr = new int(5);
	cout << *intPtr << endl;
	delete intPtr;
	return 0;
}
