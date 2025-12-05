#include <iostream>
#include <vector>
using namespace std; 


// returns ithPermutation - not uses recursion, searches correct digit for each position 
vector<int> ithPermutation(int ithPerm, int numOfDigits){

    vector<int> digits = {1,2,3,4}; 
    vector<bool> marked = {0, 0, 0, 0}; // status of the digits marked 
    vector<short> fac = {1,2,6,24}; 
    vector<int> permutation; 
    // int numOfDigits = 3; 
    // int ithPerm = 2; 
    int instantPerm = 0; 
    int numOfDigitsMarked = 0; // digits marked represents the total number of digits that have received their designated position 

    while(instantPerm < ithPerm){
        int instantDigitsScanned = 0;
        int instantPermutationsToBeAdded = 0;  
        for(int i = 0; i < numOfDigits; i++){
            if(!marked[i]){
                instantPermutationsToBeAdded = (instantDigitsScanned + 1)*fac[(numOfDigits - numOfDigitsMarked - 1) - 1]; 
                if(instantPerm + instantPermutationsToBeAdded == ithPerm){
                    instantPerm = instantPerm + instantPermutationsToBeAdded;
                    marked[i] = 1; 
                    permutation.push_back(digits[i]);  
                    break; 
                }
                if(instantPerm + instantPermutationsToBeAdded > ithPerm){
                    marked[i] = 1; 
                    permutation.push_back(digits[i]); 
                    instantPerm = instantPerm + (instantPermutationsToBeAdded - fac[(numOfDigits - numOfDigitsMarked - 1) - 1]); 
                    numOfDigitsMarked++; 
                    break; 
                }
                instantDigitsScanned++; 
            }
        } 
    }

    for(int i = numOfDigits-1; i >= 0; i--){
        if(!marked[i]) {
            permutation.push_back(digits[i]); 
        }
    }

    // for(int i = 0; i < permutation.size(); i++){
    //     cout << permutation[i]; 
    // }
    // cout << endl; 
    return permutation; 
}

// solves the two given provided permutation
pair<int,int> XandY(vector<int> permutation1, vector<int> permutation2){
    int x = 0; 
    for(int i = 0; i < permutation1.size(); i++){
        if(permutation1[i] == permutation2[i]) x++; 
    }
    int y = permutation1.size() - x; 
    return {x,y}; 
}

int main(){

    int t; 
    cin>> t; 
    
    while(t--){
        int n, j, k, numOfDigits; 
        cin >> n >> j >> k; 
        // Ik it looks ugly but works well in the given constraints 
        if(n == 12) numOfDigits = 2; 
        if(n == 123) numOfDigits = 3; 
        if(n == 1234) numOfDigits = 4; 
        pair<int,int>p; 
        if(j != k){
            p = XandY(ithPermutation(j,numOfDigits), ithPermutation(k, numOfDigits)); 
        }
        else{
            // if j and k are literally the same permutation 
            p = {numOfDigits , 0}; 
        }
        // printing the given solution 
        cout << p.first << "A" << p.second << "B" << endl; 

    }

    return 0;
}
