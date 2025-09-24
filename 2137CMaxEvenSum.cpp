#include <iostream>
#include <vector>
using namespace std; 

vector<int> getPrimeFactors(int n ){    

    int divisor = 2; 

    vector<int> primeFactors; 
    primeFactors.push_back(1); 

    while(n != 1){
        while(n % divisor == 0){
            primeFactors.push_back(divisor); 
            // cout << divisor << " "; 
            n /= divisor; 
        }
        divisor++; 
    }
    
    // cout << endl; 
    return primeFactors; 
}

long long answerForK(int a, int b, long long k){
    long long ans = (a*k) + (b/k); 
    return ans; 
}

long long subsets(vector<int> nums, int ind, long long prod, int a, int b, long long ans){

    if(answerForK(a,b,prod)%2 == 0){
        ans = max(ans, answerForK(a, b, prod)); 
    }


    // cout << ans << " "; 

    for(int i = ind; i < nums.size(); i++){
        if(ind == i || (nums[i] != nums[i-1])){
            long long newAns = subsets(nums, i+1, prod*nums[i], a, b, ans); 
            if(newAns % 2 == 0){
                ans = max(ans, subsets(nums, i+1, prod*nums[i], a, b, ans)); 
            }
        }
    }

    return ans; 
}



class Solution{
    public: 

    long long answer(long long a, long long b){
        if(a % 2 == 0 && b % 2 != 0){
            return -1; 
        }
        if(a % 2 != 0 && b % 2 != 0){
            long long k = b; 
            return (a*k) + (b/k); 
        }
        if(a % 2 != 0 && b % 4 != 0 && b % 2 == 0){
            return -1; 
        }
        if(a % 2 != 0 && b % 4 == 0){
            long long k = b/2; 
            return (a*k) + (b/k);  
        }
        if(a % 2 == 0 && b % 2 == 0){
            long long k = b/2; 
            return (a*k) + (b/k); 
        }
        return -1; 
    }


}; 

int main(){

    int t; 

    cin>> t; 

    Solution s = Solution(); 
    
    while(t--){
        long long a; 
        long long b; 

        cin >> a >> b; 

        cout << s.answer(a, b) << endl;

    }


    return 0; 
}