// just think in terms of bits and remember - 10000 is greater than 01111

#include <iostream>
#include <vector>
using namespace std;

void forEvenK(long long n, long long k){
    vector<long long> arr(k, 0); 
    int freeElem = 0; // points to the first element which is not free yet 
    for(int i = 31; i>=0; i--){
        if(n & (1LL << i)){
            // bit is set in n
            // this means we need at least one unset bit out of the k elements, let's keep arr[freeElem]'s bit unset 
            for(int j = 0; j < k; j++){
                if(j != freeElem){
                    arr[j] |= (1LL << i); 
                }
            }
            if(freeElem >= k){
                // because at least one element should have unset bit
                arr[k-1] ^= (1LL << i); 
            }
            freeElem++; 
        }
        else{
            if(freeElem % 2 == 0){
                // even number of free elements, keep in mind that freeElem points to first non-free element 
                for(int j = 0; ((j < freeElem) && (j < k)); j++){
                    arr[j] |= (1LL << i); 
                }
            }
            else{
                for(int j = 0; ((j < (freeElem-1)) && (j < k)); j++){
                    arr[j] |= (1LL << i); 
                }
            }
        }
    }
    for(long long elem : arr){
        cout << elem << " " ; 
    }
    cout << endl; 
}

void solve(long long n, long long k){
    if(k % 2 == 0){
        forEvenK(n, k); 
    }
    else{
        for(int i = 1; i <= k; i++){
            cout << n << " "; 
        }
        cout<< endl; 
    }
}

int main(){

    int t; 
    cin >> t; 

    while(t--){
        long long n, k; 
        cin >> n >> k; 
        solve(n, k);  
    }

    return 0; 
}
