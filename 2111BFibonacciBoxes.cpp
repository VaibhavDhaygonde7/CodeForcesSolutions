#include <iostream>
#include <vector>
using namespace std; 



void swap(vector<int>& arr, int ind1, int ind2){
    int temp = arr[ind1];  
    arr[ind1] = arr[ind2];  
    arr[ind2] = temp; 
}

void sortArr(vector<int>& arr){
    // note here the dimensions of the arr will be 3 no matter what 
    int ind = 0; 
    int maxElem = arr[0]; 

    for(int i = 1; i < 3; i++){
        if(maxElem < arr[i]){
            ind = i; 
            maxElem = arr[i]; 
        }
    }

    swap(arr, ind, 2); 

    if(arr[0] > arr[1]){
        swap(arr, 0, 1); 
    }

    return; 
}

char printAns(vector<int>& dimensions, int n){
    int a = 1; 
    int b = 2; 
    for(int i = 3; i <= n; i++){
        int c = a + b; 
        a = b; 
        b = c; 
    }

    // cout << a+b << " " << b << endl; 

    vector<int> newDimensions = {b, b, a+b}; 

    sortArr(dimensions); 

    for(int i = 0; i < 3; i++){
        if(dimensions[i] < newDimensions[i]){
            return '0'; 
        }
    }
 
    return '1';
}

int main(){

    int t; 

    cin >> t ;
    
    while(t--){
        int n; 
        int m ; 
        cin >> n >> m; 
        int len = m; 
        char answers[len]; 
        while(m--){
            vector<int> dimensions(3); 

            for(int i = 0; i < dimensions.size(); i++){
                cin >> dimensions[i]; 
            }

            printAns(dimensions, n); 
            answers[m] = printAns(dimensions, n);  
        }

        for(int i = len-1;  i >=0; i--){
            cout << answers[i]; 
        }

        cout << endl; 

    }

    vector<int> dimensions = {14,7,20}; 

    printAns(dimensions, 5); 

    cout << endl; 
    return 0; 
}