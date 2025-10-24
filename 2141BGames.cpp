#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;  

void games(vector<int> alice, vector<int> bob){
    int m = alice.size() ;
    int n = bob.size(); 

    unordered_set<int> set; 
    for(int n : alice) set.insert(n); 

    int k = 0; 

    for(int n : bob){
        if(set.find(n) != set.end()){
            k++; 
        }
    }

    if(m - k <= n - k){
        cout << 2*(m-k) + 1 << endl; 
    }
    else{
        cout << 2*(n-k) + 2 << endl; 
    }
}

int main(){

    int t; 
    cin >> t; 
    while(t--){
        int m, n; 
        cin >> m >> n; 

        vector<int> alice(m); 
        for(int i = 0; i < m; i++){
            cin >> alice[i]; 
        }
        vector<int> bob(n); 
        for(int i = 0; i < n; i++){
            cin >> bob[i]; 
        }

        games(alice, bob); 
    }

    return 0;
}
