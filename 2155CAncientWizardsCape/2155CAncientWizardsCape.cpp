#include <iostream>
#include <vector>
using namespace std; 

bool arrangeNextSpells(vector<int>& arr, vector<bool>& spells){
    // here we have set the spells of first two elements 
    // true indicates spell/shield towards right and false towards left 
    for(int i = 2; i < arr.size(); i++){
        if(arr[i] - arr[i-1] == 0){
            spells[i] = !spells[i-1]; 
        }
        else if(arr[i] - arr[i-1] == 1 || arr[i] - arr[i-1] == -1){
            spells[i] = spells[i-1]; 
        }
        else{
            return false; 
        }
    }
    return true; 
}

vector<int> calculateFromLeft(vector<bool> spells){
    vector<int> visibleFromLeft(spells.size()); 

    int visibleWizards = 0; 
    for(int i = 0; i < visibleFromLeft.size(); i++){
        visibleFromLeft[i] = visibleWizards;  
        if(!spells[i]) visibleWizards++; 
    }

    return visibleFromLeft; 

}

vector<int> calculateFromRight(vector<bool> spells){
    vector<int> visibleFromRight(spells.size()); 

    int visibleWizards = 0; 
    for(int i = spells.size()-1; i >=0; i--){
        visibleFromRight[i] = visibleWizards; 
        if(spells[i]) visibleWizards++; 
    }

    return visibleFromRight; 
}

bool isValid(vector<int>& arr, vector<int> visibleFromLeft, vector<int> visibleFromRight){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] - 1 != visibleFromLeft[i] + visibleFromRight[i]) return false; 
    }
    return true; 
}

int capeArrangements(vector<int>& arr){
    if(arr.size() == 1) return 2; 

    if(abs(arr[0] - arr[1]) > 1) return 0; 

    vector<bool> spells(arr.size()); 
    
    if(arr[0] > arr[1]){
        spells[0] = true; 
        spells[1] = true; 
        if(!arrangeNextSpells(arr, spells)){
            return 0; 
        }
        vector<int> visibleFromLeft = calculateFromLeft(spells); 
        vector<int> visibleFromRight = calculateFromRight(spells); 

        if(isValid(arr,  visibleFromLeft, visibleFromRight)){
            return 1; 
        }
        else{
            return 0; 
        }
    }
    else if(arr[0] < arr[1]){
        spells[0] = false; 
        spells[1] = false; 
        if(!arrangeNextSpells(arr, spells)){
            return 0; 
        }
        vector<int> visibleFromLeft = calculateFromLeft(spells); 
        vector<int> visibleFromRight = calculateFromRight(spells); 

        if(isValid(arr,  visibleFromLeft, visibleFromRight)){
            return 1; 
        }
        else{
            return 0; 
        }
    }

    int arrangments = 0; 
        spells[0] = true; 
        spells[1] = false; 
        if(arrangeNextSpells(arr, spells)){
            vector<int> visibleFromLeft = calculateFromLeft(spells); 
            vector<int> visibleFromRight = calculateFromRight(spells); 

            if(isValid(arr,  visibleFromLeft, visibleFromRight)){
                arrangments++;  
            }
        }

        spells[0] = false; 
        spells[1] = true; 
        if(arrangeNextSpells(arr, spells)){
            vector<int> visibleFromLeft = calculateFromLeft(spells); 
            vector<int> visibleFromRight = calculateFromRight(spells); 

            if(isValid(arr,  visibleFromLeft, visibleFromRight)){
                arrangments++;  
            }
        }

    return arrangments; 
}

int main(){
    
    int t; 
    cin >> t; 

    while(t--){
        int n; 
        cin >> n; 

        vector<int> arr(n); 
        for(int i = 0; i < n; i++){
            cin >> arr[i]; 
        }

        cout << capeArrangements(arr) << endl; 
    }
    
    return 0; 
}