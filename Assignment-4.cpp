#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <windows.h>

using namespace std;

/*
Output:
MENU
1. Add
2. Subtract
3. Multiply
4. Divide
5. Modulus
Enter your choice: 1
Enter your two numbers: 12 15
Result: 27

Continue? 'y'
else break!
*/


double calculate(int type, string X, string Y){

	if (type < 0 || type > 5){
		return 0;
	}

	double x = atof(X.c_str());
	double y = atof(Y.c_str());

	switch (type){

	case 1:
		return x + y;

	case 2:
		return x - y;

	case 3:
		return x * y;

	case 4:
		return x / y;

	case 5:
		return fmod(x, y);

	}

}



bool task1(){

	string x, y;
	int type;

	cout << "MENU" <<
		"\n\t1. Add"
		"\n\t2. Subtract"
		"\n\t3. Multiply"
		"\n\t4. Divide"
		"\n\t5. Modulus " << endl;

	cout << "Enter the choice: ";

	cin >> type;

	cout << "\nEnter two numbers: ";

	cin >> x >> y;

	cout << "Result: " << calculate(type, x, y) << endl;

	char again;

	cout << "Continue? Enter 'y'" << endl;

	cin >> again;

	if (again == 'y') return true;
	
	return false;

}



int _tmain(int argc, _TCHAR* argv[])
{

	while (task1()){

		system("cls");

	}

	return 0;
}
