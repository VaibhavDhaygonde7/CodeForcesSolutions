#include <iostream>
#include <vector>
using namespace std; 

// if you are getting confused with negative remainders, here's the video 
// https://www.youtube.com/watch?v=k0ybrHWX1ZI

void add0orK(vector<long long> arr, int k){
    int g = k + 1; 
    for(int i = 0; i < arr.size(); i++){
        long long m =arr[i] % g; 
        long long factor = m * k; 
        arr[i] += factor; 
    }

    for(long long n : arr) cout << n << " " ; 
    cout << endl; 
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; 
    cin>> t; 

    while(t--){
        int n, k; 
        cin>> n >> k; 

        vector<long long> arr(n); 

        
        for(int i = 0; i < n; i++){
            cin >> arr[i]; 
        }

        add0orK(arr, k);
    }

    return 0;
}
