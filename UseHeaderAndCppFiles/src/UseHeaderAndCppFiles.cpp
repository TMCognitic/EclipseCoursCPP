//============================================================================
// Name        : UseHeaderAndCppFiles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Header.h"

int main(int parameterCount, char** parameter)
{
	cout << "9 + 4 = " << Add(9, 4) << endl;
	getchar();
}
