
#include "stdafx.h"
#include "string"
#include <iostream>
#include <math.h>
#define PI 3.14159265

using namespace std;


void areaOfCircle(){

	/*task 1*/
	
	double r;

	cout << "Type the radius: ";

	cin >> r;

	cout << "The area is " << r * r * PI << "\n\n";

}

void ferToCel(){

	/*
	C = (F - 32) / 1.8
	F = (1.8 * C) + 32
	*/

	double f;

	cout << "Type the Fahrenheit: ";

	cin >> f;

	cout << f << "F is " << (f-32)/1.8 << "C\n\n";

}

void galToLiter(){

	double g;

	cout << "Type the Gallon: ";

	cin >> g;

	cout << g << "gallon is " << g*3.785411784 << "liter\n\n";
}

//////////////////

double getChange(double moneyOwe, double moneyGot){

	return moneyOwe - moneyGot;

}

void tellChange(double result){

	cout.precision(2);
	cout << std::fixed;

	if (result > 0){
		cout << "\n\nYou owe $" << result << endl;
	}
	else{
		cout << "Wow, you gave me $" << abs(result) << " more!" << endl;
	}

}

////////////////////

void getInfoAndPrint(){


	string name, address, citizenship;
	int age;

	cout << "\n\nWhat's your age? : ";

	cin >> age;

	cout << "What's your name? : ";

	cin.ignore();

	getline(cin, name);

	cout << "What's your address? : ";

	getline(cin, address);

	cout << "What's your citizenship? : ";

	getline(cin, citizenship);

	cout << "Your age: " << age
		<< "\nYour name: " << name
		<< "\nYour address: " << address
		<< "\nYour citizenship: " << citizenship << endl;

}

int _tmain(int argc, _TCHAR* argv[])
{
	areaOfCircle();
	ferToCel();
	galToLiter();

	double price = 100.2512;
	double money = 178.5014;

	tellChange(getChange(price, money));

	getInfoAndPrint();

	return 0;
}
