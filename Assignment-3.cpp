
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <windows.h>

using namespace std;

/*
1. Write a C++ program that will print the following pattern

*******
******
*****
****
***
**
*
2. Write a program that will print the following pattern:
1******
12*****
123****
1234***
12345**
123456*
1234567

3. Write a C++ program that will print the pattern as shown below:

*
***
*****
*******
*********
*********
*******
*****
***
*

*/

void task1() {

	int howMany;

	int maxLength;

	cout << "-----Task 1-----" << endl;

	cout << "How many times do you want to reapeat: ";

	cin >> howMany;

	cout << "\nWhat is the max amount of the stars: ";

	cin >> maxLength;

	for (int c = 0; c < howMany; c++) {

		for (int a = 0; a < maxLength; a++) {

			for (int b = 0; b <= a; b++) {

				cout << "*";
			}

			cout << endl;

			Sleep(200);
		}
	}

}

void task2() {

	int maxLength;

	cout << "\n\n-----Task 2-----" << endl;

	cout << "What is the Max number: ";

	cin >> maxLength;

	int starLength = maxLength;
	int numlength = 1;


	for (int c = 0; c < maxLength; c++) {

		for (int b = 1; b <= numlength; b++) {
			cout << b;
		}

		for (int a = 1; a < starLength; a++) {
			cout << "*";
		}
		cout << endl;

		starLength--;
		numlength++;

		Sleep(200);

	}

}

void task3() {

	int howMany;

	int maxLength;

	cout << "\n\n-----Task 3-----" << endl;

	cout << "How many times do you want to reapeat: ";

	cin >> howMany;

	cout << "\nWhat is the max amount of the stars: ";

	cin >> maxLength;

	for (int a = 0; a < howMany; a++) {

		for (int b = 0; b <= maxLength; b++) {

			cout << "*";

			for (int c = 0; c < b; c++) {
				cout << "**";
			}
			cout << endl;

			Sleep(100);
		}

		for (int b = maxLength; b >= 0; b--) {

			cout << "*";

			for (int c = 0; c < b; c++) {
				cout << "**";
			}
			cout << endl;
			Sleep(100);
		}
	}



}


int _tmain(int argc, _TCHAR* argv[])
{

	task1();
	task2();
	task3();

	return 0;
}
