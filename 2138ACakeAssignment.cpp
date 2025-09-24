#include <iostream>
#include <vector>
#include <math.h>
using namespace std; 

class Solution{
    public: 

    int findSmallestPath(int k, int x){
        int chocola = pow(2, k); 
        int vanilla = chocola; 

        vector<int> path(k+1, -1); 

        int returnValue = recursion(x, chocola, vanilla, path, 0); 

        if(returnValue == 1){
            for(int n : path){
                if(n == -1) break; 
                cout << n << " "; 
            }
        }
        
        if(returnValue == 2){
            for(int n : path){
                if(n == 1) cout << "2 "; 
                if(n == 2) cout << "1 "; 
                if(n == -1) break; 
            }
        }

        cout << endl;

        return 0; 
    }

    int recursion(int x, int chocola, int vanilla, vector<int>&path, int ind){
        if(chocola == x || vanilla == x){
            cout << ind << endl; 
            // for(int n : path){
            //     cout << n << " "; 
            // }
            // cout << endl; 
            if(chocola == x) return 1; 
            return 2;  
        }

        if(ind == path.size()) return 0; 

        // cout << chocola << " " << vanilla << endl; 

        if(chocola%2 == 0){
            path[ind] = 1; 
            int returnValue = recursion(x, chocola/2, vanilla + (chocola/2), path, ind+1); 
            
            if(returnValue != 0) return returnValue; 
            
            path[ind] = 2; 
            returnValue = recursion(x, chocola + (vanilla/2), vanilla/2, path, ind+1); 
            if(returnValue != 0) return returnValue; 
        }

        path[ind] = -1; 

        return 0; 
    }   


}; 

// hint --> do you think that the path to the final desired state is a unique path? you can realise this after drawing recursion tree. Instead of going from initial state to final state, if the path is unique, can you from final state to initial state?
class Solution2{
    public:  
    void findSmallestPath(int k, long long x){

        
        long long initialState = 1LL << k; 
        
        if(!x || x == initialState*2){
            cout << "0 "<< endl << endl; 
            return; 
        }

        long long chocola = x; 
        long long vanilla = (initialState*2) - x; 

        // cout << chocola << " " << vanilla << endl; 
        
        vector<int> path; 

        while(chocola != initialState && vanilla != initialState){
            if(chocola < initialState){
                path.push_back(1); 
                vanilla -= chocola; 
                chocola += chocola;  
            }
            else{
                path.push_back(2); 
                chocola -= vanilla; 
                vanilla += vanilla; 
            }
            // cout<< endl; 
            // cout << chocola << " " << vanilla << endl; 
        }

        cout << path.size() << endl; 
        for(int i = path.size()-1; i>= 0; i--){
            cout << path[i] << " "; 
        }
        cout << endl; 

    }
}; 

int main(){

    Solution2 s2 = Solution2(); 

    // s2.findSmallestPath(4, 17); 

    // Solution s = Solution(); 

    int t; 

    cin >> t;

    while(t--){
        long long k, x; 
        cin >> k; 
        cin >> x; 
        s2.findSmallestPath(k, x); 
    }

    return 0; 
}