// Not done

#include "stdafx.h"

#include <iostream>     // std::cout
#include <algorithm>    // std::minmax

using namespace std;




/*
May not needed

int getArrLenght(double arr[]){

return sizeof(arr) / sizeof(arr[0]);

}
*/

double getLargest(double arr[], int arraySize){

	double max = arr[0];

	for (int i = 0; i < arraySize; i++){


		if (arr[i] > max) max = arr[i];

	}

	return max;

}

double getSmallest(double arr[], int arraySize){

	double min = arr[0];

	for (int i = 0; i < arraySize; i++){

		if (arr[i] < min) min = arr[i];

	}

	return min;

}

double getFrenquentNum(double arr[], int arraySize){

	double num;

	for (int i = 0; i < arraySize; i++){

		if (arr[i] < num) num = arr[i];

	}

	return num;

}




void task1(){
	const int ARRAYSIZE = 10;
	double values[ARRAYSIZE];
	double small, big;

	for (int i = 0; i < ARRAYSIZE; i++)
	{
		cout << i + 1 << ". Enter value: ";
		cin >> values[i];
	}

	cout << "Largest is: "<< getLargest(values, ARRAYSIZE) << endl;
	cout << "Smallest is: " << getSmallest(values, ARRAYSIZE) << endl;

}




int main() {

	task1();


	return 0;



	
		auto result = std::minmax({ 1, 2, 3, 4, 5 });

		cout << result.first << ' ' << result.second << '\n';
		

}










