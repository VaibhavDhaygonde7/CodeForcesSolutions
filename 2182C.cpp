#include <iostream>
#include <vector>
using namespace std; 

bool isValid(vector<int> arr1, vector<int> arr2, vector<int> arr3, int ind1, int ind2, int ind3){
    int n = arr1.size();    
    for(int i = 0; i < n; i++){
        if(arr1[(ind1 + i) % n] < arr2[(ind2 + i) % n] && arr2[(ind2 + i)%n] < arr3[(ind3 + i) % n]){
            continue;
        }
        else{
            return false; 
        }
    }
    return true;    
}


long long solve(vector<int> arr1, vector<int> arr2, vector<int> arr3){
    long long ans = 0; 

    int n = arr1.size(); 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(isValid(arr1, arr2, arr3, i, j, k)) ans+=1; 
            }
        }
    }

    return ans; 
}


bool isValid(vector<int>& arr1, vector<int>& arr2, int ind1, int ind2){
    for(int j = 0; j < arr2.size(); j++){
        if(arr1[(j + ind1) % arr1.size()] >= arr2[(j+ind2)%arr1.size()]) return false; 
    }
    return true; 
}

long long giveAnswerArr(vector<int>& arr1, vector<int>& arr2){
    // vector<int> answer(arr1.size(), 0); 
    long long answer = 0; 
    for(int i = 0; i < arr1.size(); i++){
        if(isValid(arr1, arr2, 0, i)) answer++; 
    }
    return answer; 
}


long long solve2(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3){
    long long answer1 = giveAnswerArr(arr1, arr2); 
    long long answer2 = giveAnswerArr(arr2, arr3); 



    return arr1.size() * answer1 * answer2; 
}

int main(){

    int t; 
    cin >> t; 

    while(t--){
        int n; 
        cin >> n; 

        vector<int> arr1(n); 
        vector<int> arr2(n); 
        vector<int> arr3(n); 

        for(int i = 0; i < n; i++) cin >> arr1[i]; 
        for(int i = 0; i < n; i++) cin >> arr2[i]; 
        for(int i = 0; i < n; i++) cin >> arr3[i]; 

        cout << solve2(arr1, arr2, arr3) << endl; 

    }

    return 0; 
}
