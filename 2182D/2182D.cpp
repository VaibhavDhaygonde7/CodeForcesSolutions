#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

long long mod = 998244353; 

long long power(long long a, long long b){
    long long res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

long long modInverse(long long a){
    return power(a, mod - 2);
}

int findMax(vector<int>& arr){
    int maxElem = arr[1]; 
    for(int i = 2; i < arr.size(); i++){
        maxElem= max(maxElem, arr[i]); 
    }
    return maxElem; 
}

long long minFirstElem(vector<int>& arr, int maxElem){
    long long minValue = 0; 

    for(int i = 1; i < arr.size(); i++){
        if(arr[i] == maxElem) continue; 
        minValue += (maxElem-arr[i]-1); 
    }
    return minValue; 
}

long long fac(int n){
    long long ans = 1; 
    for(int i = 1; i <= n; i++){
        ans %= mod; 
        ans*=i; 
        ans %= mod; 
    }
    return ans%mod; 
}

int frequencyOfElem(vector<int> arr, int elem){
    int freq = 0; 
    for(int i = 1; i < arr.size(); i++){
        if(elem == arr[i]) freq++; 
    }
    return freq; 
}

long long nCr(int n, int r){
    if(r > n) return 0; 
    long long answer = 1; 
    int denominator = 1; 
    int numerator = n; 
    while(denominator <= r){
        
        answer %= mod;
        answer *= numerator; 
        answer %= mod;
        answer = answer * modInverse(denominator) % mod;
       
        numerator--; 
        denominator++; 
    }
    return answer%mod; 
}

long long solve(vector<int>& arr){
    int n = arr.size() - 1; 
    int maxElem = findMax(arr); 
    long long minValue = minFirstElem(arr, maxElem); 

    if(minValue > arr[0]) return 0; 

    long long answer = 1; 

    int freqMaxElem = frequencyOfElem(arr, maxElem);

    // if(freqMaxElem == 1){
    //     long long numOfIterations = -1 ;
    //     if(n < (arr[0] - minValue + 1)) numOfIterations = n; 
    //     else numOfIterations = arr[0] - minValue + 1; 
        
    //     for(int i = 0; i < numOfIterations; i++){
    //         answer %= mod; 
    //         answer += (fac(n-1)%mod); 
    //         answer %= mod; 
    //     }
    //     return answer; 
    // }

    int availableIndicesForMaxElem = -1; 
    if(n < arr[0] - minValue + freqMaxElem){
        // cout << fac(n-1) << endl; 
        return (fac(n)% mod); 
    }
    else{
        availableIndicesForMaxElem = arr[0] - minValue + freqMaxElem; 
        // cout << "Available Indices: " << availableIndicesForMaxElem<<endl;
        int remainingIndices = availableIndicesForMaxElem; 
        // long long answer = 1; 
        // allocated indices for max elem
        answer *= (nCr(availableIndicesForMaxElem, freqMaxElem));

        // allocating indices for remaining elems
        // these elems can go to any of the indices 
        answer *= 1;

        // now permuting their positions
        answer%=mod; 
        answer *= (fac(freqMaxElem) % mod); 
        answer%=mod; 
        answer *= (fac(n-freqMaxElem) % mod); 
        answer %= mod; 
        return answer; 
    }

    // cout << "FUCKING HELL" << endl; 

    return -1; 
}


int main(){

    int t; 

    cin >> t; 

    while(t--){
        int n; 
        cin >> n; 
        vector<int> arr(n+1); 
        for(int i = 0; i < n+1; i++) cin >> arr[i];
        cout << solve(arr) << endl; 
    }
}
