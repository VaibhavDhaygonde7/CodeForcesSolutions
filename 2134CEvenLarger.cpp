#include <iostream>
#include <vector>
using namespace std; 


// what's the worst subarray we can pick??... a subarray of size 3 with even index (with respect to original arr) in middle of it... x y z... x + z <= y... and y is at an even index
void evenLarger(vector<int> arr){
    long long count = 0; 
    for(int i = 1; i<arr.size(); i+=2){
        int sum = arr[i-1]; 
        if(i + 1 < arr.size()){
            sum += arr[i+1]; 
        }
        if(sum > arr[i]){
            if(i + 1 < arr.size()){
                count += sum - arr[i]; 
                if(sum - arr[i] > arr[i+1]){
                    arr[i+1] = 0; 
                }
                else{
                    arr[i+1] -= (sum - arr[i]); 
                }
            }
            else{
                count += sum - arr[i]; 
            }
        }
        // cout << count << " "; 
    }
    // cout << endl; 
    // for(int n : arr) cout << n << " "; 
    // cout << endl; 
    cout << count << endl; 
}

int main(){

    int t; 
    cin >> t; 

    while(t--){
        int n ; 
        cin >> n; 
        vector<int> arr(n); 


        for(int i = 0; i < n; i++){
            cin >> arr[i]; 
        }

        evenLarger(arr); 
    }
}
