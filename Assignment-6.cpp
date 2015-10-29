
//include <stdafx> //if visual studio
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*

1.	Write a C++ program to sort 10 integer values (reading from keyboard) in ascending and descending order.

Example Output:

Enter 10 number:
1 3 4 8 2 6 7 9 10

Ascending: 
 1 2 3 4 5 6 7 8 9 10

Decending:
10 9 8 7 6 5 4 3 2 1

*/


int* sortArray(int arr[], int ARRAYSIZE){
    
    for(int b = 0; b < ARRAYSIZE; b++){
        
        for(int a = 0; a < ARRAYSIZE - 1; a++){
            
            int temp = arr[a];
        
            if(temp > arr[a+1]){
         
                arr[a] = arr[a+1];
         
                arr[a+1] = temp; 
            
            }
        }
    }
    
    return arr;
}

int* reverseArray(int arr[], int ARRAYSIZE){
    
    for(int a = 0; a < ARRAYSIZE / 2; a++){
        
        int temp = arr[a];
        
        arr[a] = arr[ARRAYSIZE - 1 - a];
        
        arr[ARRAYSIZE - 1 - a] = temp;
    }
    
    return arr;
}



void task1(){
    
    cout << "Enter 10 integers: " << endl;
    
    const int ARRAYSIZE = 11;
    
    int arr[ARRAYSIZE];
    
    for(int a = 0; a < ARRAYSIZE; a++){
        
        cin >> arr[a];
        
    }

    cout << "Ascending: " << endl;
    
    int* arr2 = sortArray(arr, ARRAYSIZE);
    
    for(int a = 0; a < ARRAYSIZE; a++) {
        
    cout << arr2[a];
    
    if(a != ARRAYSIZE-1) cout << ", ";
    
    }
    
    cout << endl;
        
    cout << "Decending: " << endl;
    
    arr2 = reverseArray(arr2, ARRAYSIZE);
    
    for(int a = 0; a < ARRAYSIZE; a++) {
        
    cout << arr2[a];
    
    if(a != ARRAYSIZE-1) cout << ", ";
    
    }
    
    cout << endl;    
        
}


int main()
{
    task1();
    
    return 0;
}



