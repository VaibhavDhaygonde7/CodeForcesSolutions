#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std; 

void solve(string s){

    int prefixSum = 0; 

    vector<int> prefixArr(s.length()+1); 

    prefixArr[0] = 0;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'a'){
            prefixSum++; 
            prefixArr[i+1] = prefixSum; 
        }
        else{
            prefixSum--; 
            prefixArr[i+1] = prefixSum;
        }
    }

    if(prefixSum == 0){
        cout << 0 << endl; 
    }
    else{
        int target = prefixSum; 
        unordered_map<int, int> map; 
        map.insert({0,0}); 

        int minSubStrLen = __INT_MAX__; 

        for(int i = 1; i < prefixArr.size(); i++){
            if(map.find(prefixArr[i] - target) != map.end()){
                minSubStrLen = min(minSubStrLen, i - map[prefixArr[i] - target]);
                map[prefixArr[i]] = i;  
            }
            else{
                // map.insert({prefixArr[i], i}); 
                map[prefixArr[i]] = i; 
            }
        }

        if(minSubStrLen == s.length()){
            cout << -1 << endl; 
        }
        else{
            cout << minSubStrLen << endl; 
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

        solve(s); 

    }

    return 0;  
}
