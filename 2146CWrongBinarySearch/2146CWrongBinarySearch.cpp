#include <iostream>
#include <vector>
using namespace std; 

vector<pair<int,int>> findConsecutiveZerosIndices(string s){
    int ind = 0;
    vector<pair<int,int>> consecutiveZeros; 
    while(ind < s.length()){
        if(s[ind] == '0'){
            int begInd = ind; 
            while(ind < s.length() && s[ind] == '0') ind++; 
            int endInd = ind-1; 
            if(endInd - begInd + 1 == 1){
                consecutiveZeros.push_back({-1,-1}); 
                break; 
            }
            else{
                consecutiveZeros.push_back({begInd, endInd}); 
            }
        }
        else{
            ind++; 
        }
    }
    return consecutiveZeros; 
}

void swap(vector<int>& arr, int ind1, int ind2){
    int temp = arr[ind1]; 
    arr[ind1] = arr[ind2]; 
    arr[ind2] = temp; 
}

void reverse(vector<int>& arr, int ind1, int ind2){
    for(int i = 0; i < (ind2-ind1+1)/2; i++){
        swap(arr, ind1 + i, ind2 - i ); 
    }
}

void printPermutation(string s){
    vector<int> arr(s.length()); 
    for(int i = 0; i < arr.size(); i++){
        arr[i] = i + 1; 
    }

    vector<pair<int,int>> consecutiveZeros = findConsecutiveZerosIndices(s); 

    if(consecutiveZeros.size() == 0){
        cout << "YES" << endl; 
        for(int n : arr) cout << n << " "; 
        cout << endl; 
    }
    else{
        if(consecutiveZeros[consecutiveZeros.size() - 1 ].first == -1){
            cout << "NO" << endl;  
        }
        else{
            cout << "YES" << endl;
            for(pair<int,int> p : consecutiveZeros){
                swap(arr, p.first, p.second); 
            }
            for(int n : arr) cout << n << " "; 
            cout << endl; 
        }
    }
}

int main(){

    int t; 
    cin >> t; 

    while(t--){
        int n; 
        string s; 
        cin >> n >> s; 
        printPermutation(s); 
    }

    return 0; 
}
