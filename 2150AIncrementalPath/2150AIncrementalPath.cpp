#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std; 

int nextWhite(unordered_set<int>& set, int currentPoint){
    int point = currentPoint+1; 
    while(true){
        if(set.find(point) == set.end()){
            // set.insert(point); 
            break; 
        }
        point++; 
    }
    return point; 
}

void solve(unordered_set<int> set, string s){
    int currentPoint = 1; 

    for(int i = 0; i < s.length(); i++){
        if(i > 0){
            if(s[i-1] == 'B'){
                currentPoint = nextWhite(set, currentPoint);
                // cout << currentPoint << endl;  
                // set.insert(currentPoint); 
            }
            if(s[i] == 'A'){
                currentPoint++; 
                // set.insert(currentPoint); 
            } 
            else{
                currentPoint = nextWhite(set, currentPoint); 
                // set.insert(currentPoint); 
            }
        }
        else{
            if(s[i] == 'A'){
                currentPoint++; 
                // set.insert(currentPoint); 
            } 
            else{
                currentPoint = nextWhite(set, currentPoint); 
                // set.insert(currentPoint); 
            }
        }
        set.insert(currentPoint);
    }
    vector<int> arr(set.size()); 
    int ind = 0; 
    for(int n : set){
        arr[ind] = n; 
        ind++; 
    }
    sort(arr.begin(), arr.end()); 

    cout <<  arr.size() << endl; 

    for(int n : arr){
        cout << n << " "; 
    }
    cout << endl;
}

int main(){

    int t; 
    cin >> t; 

    while(t--){
        int n, m; 
        string s; 
        cin >> n >> m >> s; 
        unordered_set<int> set; 
        for(int i = 0; i < m; i++){
            int temp; 
            cin >> temp; 
            set.insert(temp);  
        }

        solve(set, s); 

    }

    return 0; 
}