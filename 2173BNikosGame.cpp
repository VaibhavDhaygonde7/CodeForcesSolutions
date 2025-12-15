#include <iostream>
#include <vector>
using namespace std; 

long long maxScore(vector<int>& a, vector<int>& b){
    long long k1 = 0; // instantMaxScore
    long long k2 = 0; // instantMinScore 

    for(int i = 0; i < a.size(); i++){
        long long tempK1 = k1; 
        k1 = max(k1 - a[i], b[i] - k2); 
        k2 = min(b[i] - tempK1, k2 - a[i]); 
    }

    return k1; 
}

// long long dpApproach(vector<int>& a, vector<int>& b, long long k, int ind){
//     if(ind == a.size()){
//         return k;  
//     }

//     long long k1 = dpApproach(a, b, k - a[ind], ind+1);
//     long long k2 = dpApproach(a, b, b[ind] - k, ind+1);

//     return max(k1, k2);
// }

int main(){

    int t; 
    cin >> t; 

    while(t--){
        int n; 
        cin>>n; 
        vector<int> a(n); 
        vector<int> b(n); 

        for(int i = 0; i < n; i++){
            cin >> a[i]; 
        }
        for(int i = 0; i < n; i++){
            cin >> b[i]; 
        }
        
        cout << maxScore(a, b) << endl; 
    }

    return 0; 
}
