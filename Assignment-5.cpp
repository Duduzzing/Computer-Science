
#include "stdafx.h"
#include <iostream>
#include <algorithm>    // std::minmax
#include <vector>

using namespace std;


//not done

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

auto result = std::minmax({ 1, 2, 3, 4, 5 });

cout << result.first << ' ' << result.second << '\n';

*/


int indexOfVector(vector<double>* vec, double toFind){

	cout << "vec size: " << vec->size() << endl;

	for (int a = 0; a < vec->size() - 1; a++){

		if (toFind == vec[a]) return a;

	}

	return -1;

}

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


double getMode(double arr[], int arraySize){

	double mode = arr[0];

	vector<double> numbers;
	vector<int> count;

	for (int a = 0; a < arraySize; a++){

		int index = indexOfVector(&numbers, arr[a]);

		if (index + 1){
			numbers.push_back(arr[a]);
			count.push_back(1);
		}
		else{
			count[index]++;
		}

	}

	for (int i = 0; i < count.size()-1; i++){

		if (count[i] > mode) mode = count[i];

	}

	return mode;

}




void task1(){
	const int ARRAYSIZE = 10;
	double values[ARRAYSIZE] = {5,2,3,4,5,6,7,8,9,1};
	double small, big;

	/*
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		cout << i + 1 << ". Enter value: ";
		cin >> values[i];
	}
	*/

	cout << "Largest is: " << getLargest(values, ARRAYSIZE) << endl;
	cout << "Smallest is: " << getSmallest(values, ARRAYSIZE) << endl;
	cout << "Mode is: " << getMode(values, ARRAYSIZE) << endl;
}




int main() {

	task1();

	return 0;


}









