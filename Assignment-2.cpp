

#include "stdafx.h"
#include "string"
#include <iostream>
#include <math.h>

using namespace std;


void task1(){
	int x = 10, y = 5;

	cout << "Task1:\n";

	cout <<
		"x value y   value   expressions   results" << endl <<
		"10 | 5 | x = y + 3 | x = " << y + 3 << endl <<
		"10 | 5 | x = y - 2 | x = " << y - 2 << endl <<
		"10 | 5 | x = y * 5 | x = " << y * 5 << endl <<
		"10 | 5 | x = x / y | x = " << x / y << endl <<
		"10 | 5 | x = x%y | x = " << x % y << endl;

}

void task2(){
	int x = 5;

	cout << "\nTask2:\n";

	cout << "Contents of x before | Expression | Value of Expression | Contents of x after" << endl;

	x = 5;
	x++;

	cout << "          5          | x++        |           5         |     " << x << "    " << endl;

	x = 5;
	x--;

	cout << "          5          | x--        |           5         |     " << x << "    " << endl;

	x = 5;
	++x;

	cout << "          5          | ++x        |           6         |     " << x << "      " << endl;

	x = 5;
	--x;

	cout << "          5          | --x        |           4         |     " << x << "      " << endl;

}

void task3(){

	cout << "\nTask3:\n";

	int x, y, z;
	int biggest;

	cout << "Enter 3 numbers: ";

	cin >> x >> y >> z;

	if (x > y){
		biggest = x;

	}
	else {
		biggest = y;
	}

	if (biggest < z){
		biggest = z;
	}

	cout << biggest << " is the biggest!!!!!" << endl;
}


void task4(){

	int avg = 0;
	string grade;
	int quiz, assignment, test;

	cout << "\nTask4:\n";

	cout << "What's your quiz mark? /10 : ";
	cin >> quiz;

	cout << "\nWhat's your assignment mark? /10 : ";
	cin >> assignment;

	cout << "\nWhat's your test mark? /10 : ";
	cin >> test;

	avg = (quiz + assignment + test) / 30 * 100;



	if (avg >= 90) grade = "A";
	else if (avg >= 70 && avg < 90) grade = "B";
	else if (avg >= 50 && avg < 70) grade = "C";
	else if (avg < 50) grade = "F";

	cout << "Your grade is " << grade << endl;

}


int _tmain(int argc, _TCHAR* argv[])
{
	task1();
	task2();
	task3();
	task4();

	return 0;
}
