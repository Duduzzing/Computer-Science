
#include "stdafx.h"
#include <iostream>
#include <algorithm>    // std::minmax
#include <vector>
#include <algorithm>

using namespace std;

/*
1. Write a C++ program that will prompt the user to input ten integer values.
The program will display the smallest and greatest of those values.It also displays the value that occurs the most.
(remember good programming practices)

Example Output :

Enter in 10 values :
5 12 22 22 1 32 5 3 4 12

Smallest value is 1.
Greatest value is 32.
*/

/*
May not needed

int getArrayLength(double arr[]){

return sizeof(arr) / sizeof(arr[0]);

}

//and some trick
auto result = std::minmax({ 1, 2, 3, 4, 5 });

cout << result.first << ' ' << result.second << '\n';

*/


int indexOfVector(vector<double> vec, int size, double toFind) {

	for (int a = 0; a < size; a++) {

		if (toFind == vec[a]) return a;

	}

	return -1;

}

double getLargest(double arr[], int arraySize) {

	double max = arr[0];

	for (int i = 0; i < arraySize; i++) {


		if (arr[i] > max) max = arr[i];

	}

	return max;

}

double getSmallest(double arr[], int arraySize) {

	double min = arr[0];

	for (int i = 0; i < arraySize; i++) {

		if (arr[i] < min) min = arr[i];

	}

	return min;

}

//occurs most
double getMode(double arr[], int arraySize) {

	double mode = arr[0];

	vector<double> numbers;
	vector<int> count;

	for (int a = 0; a < arraySize; a++) {

		int index = indexOfVector(numbers, numbers.size(), arr[a]);

		if (index + 1 == false) {
			numbers.push_back(arr[a]);
			count.push_back(1);
		}
		else {
			count[index]++;
		}
		

	}

	for (int i = 0; i < count.size(); i++) {

		if (count[i] > mode) mode = numbers[i];

	}

	return mode;

}

//average
double getMean(double arr[], int arraySize) {

	int total = 0;

	for (int a = 0; a < arraySize; a++)
		total += arr[a];

	return total / arraySize;

}

//middle
double getMedian(double arr[], int arraySize) {

	double median;

	//is even
	if (arraySize % 2 == false) {

		median = (arr[arraySize / 2 - 1] + arr[arraySize / 2]) / 2;

	}
	//is odd
	else {

		median = arr[(arraySize - 1) / 2];

	}

	return median;

}




void task1() {
	const int ARRAYSIZE = 10;
	double values[ARRAYSIZE];
	double small, big;

	
	for (int i = 0; i < ARRAYSIZE; i++)
	{
	cout << i + 1 << ". Enter value: ";
	cin >> values[i];
	}

	sort(values, values + ARRAYSIZE);

	cout << "\n[";

	for (int i = 0; i < ARRAYSIZE; i++) {

		cout << values[i];

		if (i != ARRAYSIZE - 1)
			cout << ", ";

	}

	cout << "]" << endl;

	cout << "Largest is:		" << getLargest(values, ARRAYSIZE) << endl;
	cout << "Smallest is:		" << getSmallest(values, ARRAYSIZE) << endl;
	cout << "Mode is:		" << getMode(values, ARRAYSIZE) << endl;
	cout << "Mean is:		" << getMean(values, ARRAYSIZE) << endl;
	cout << "Median is:		" << getMedian(values, ARRAYSIZE) << "\n\n";

}

int main() {

	task1();

	return 0;

}

