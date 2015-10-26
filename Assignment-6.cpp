
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


void task1(){
    
    cout << "Enter 10 integers: ";
    
    int arr[10];
    
    for(int a = 0; a < 10; a++) 
        cin >> arr[a];
        
    cout << "Ascending: ";
    
    sort(arr, arr + 10);
    
    for(int a = 0; a < 10; a++) {
        
    cout << arr[a];
    
    if(a != 9) cout << ", ";
    
    }
    
    cout << endl;
        
    cout << "Decending: ";
    
    reverse(arr, arr + 10);
    
    for(int a = 0; a < 10; a++) {
        
    cout << arr[a];
    
    if(a != 9) cout << ", ";
    
    }
    
    cout << endl;    
        
        
    
}


int main()
{
    task1();
    
    return 0;
}




