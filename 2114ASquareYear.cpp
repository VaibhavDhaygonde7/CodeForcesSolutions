#include <iostream>
#include <math.h>
using namespace std; 


int main(){

    int cases; 

    cin >> cases;

    while(cases){
        string str_num; 
        cin >> str_num; 

        int num = stoi(str_num); 

        int squareRoot = sqrt(num); 

        if(squareRoot*squareRoot != num){
            cout << -1 << endl; 
        }
        else{
            cout << squareRoot/2 << " " << squareRoot - (squareRoot/2) << endl; 
        }
        cases--; 
    }

    return 0; 
}