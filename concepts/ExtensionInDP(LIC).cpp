// this is a bit different type of DP. the value at index i also depends on the past choices we have made 
// basically in this question we are extending a answer which we have previously found
// this question is available on LC

#include <iostream>
#include <vector>
using namespace std; 

int LIC(vector<int> arr){
    vector<int> dp(arr.size()); 

    for(int i = 0; i < arr.size(); i++){
        int extension = -1; 
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                // this means that there exists an element which is smaller than arr[i] and is a part of a pre-existing subsequence. So if a subsequence does exist then we will just extend it by 1 as we have found a larger element
                extension = max(extension, dp[j]+1); 
            }
        }
        // if extension is not found than this means that arr[i] is beginning of a new subsequence
        dp[i] = max(1, extension); 
    }

    int maxLen = dp[0]; 
    for(int n : dp) {
        maxLen = max(maxLen, n); 
        // cout << n << " " ; 
    }
    // cout << endl; 

    return maxLen; 
}

int main(){

    vector<int> arr = {1,4,2,5,3,5}; 

    cout << LIC(arr) << endl; 

    return 0; 
}
