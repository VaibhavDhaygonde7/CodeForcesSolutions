#include <iostream>
#include <vector>
using namespace std; 

int main(){

    // A philosophical hint so as to explain why this approach works ;)
    // The starting point doesn't matter, ending point does ;)
    // also this is possible only because the array contains possible integers xD

    int t; 
    cin >> t; 

    while(t--){
        int n, lowerBound, upperBound ;

        cin >> n >> lowerBound >> upperBound; 
        vector<int> arr(n); 

        for(int i = 0; i < n; i++) cin >> arr[i]; 
    
        int low = 0; 
        int high = 0; 
    
        int instantSum = 0; 
    
        int count = 0; 
    
        while(low <= high && high < arr.size()){
            while(high < arr.size() && instantSum < lowerBound){
                instantSum += arr[high]; 
                high++; 
            }
            // cout << instantSum << endl; 
            if(instantSum <= upperBound && instantSum >= lowerBound){
                count++; 
                low = high; 
                instantSum = 0; 
            }
            else{
                while(instantSum > upperBound){
                    instantSum -= arr[low]; 
                    low++; 
                }
                if(instantSum >= lowerBound){
                    count++; 
                    low = high; 
                    instantSum = 0;  
                }
            }
        }
    
        cout << count << endl; 
    }


    return 0; 
}
