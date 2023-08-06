#include<bits/stdc++.h>
using namespace std;

//Approach 1
//T.C -> O(N), S.C -> O(N)
int missingNumber_one(int arr[], int n){ 
    vector<bool> miss(1e6 + 1, false);
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] <= 0){
            continue;
        }
        miss[arr[i]] = true;
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    if(mini != 1){
        return 1;
    }
    for(int i = mini; i <= maxi; i++){
        if(miss[i] == false){
            return i;
        }
    }
    return maxi + 1;
}

//Approach 2
//T.C -> O(N), S.C -> O(1)
//Uses concept of hashing
int missingNumber_two(int arr[], int n){
    for(int i = 0; i < n; i++){
        if(arr[i] <= 0){ 
            arr[i] = n + 1; //if a particular number is less than or equal to 0, then replace it by n + 1;
        }
    }
    //After the above process all the elements of the array will be positive integers
    //Now in the below loop, we will go to each and every element and consider an index which equals element - 1;
    //Now we will go to that index and multiply the element present in that index with -1;
    //This means that if an element x is present in the array, then arr[x - 1] will be negative.
    for(int i = 0; i < n; i++){
        int index = abs(arr[i]) - 1;
        if(index < n and arr[index] > 0){ //arr[index] > 0 to avoid considering the duplicate cases
            arr[index] *= -1;
        }
    }
    //In the below loop, if we find any element greater than 0, then that means (element's index + 1) element is not present in the array
    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            return i + 1;
        }
    }
    return n + 1; //If all the elements from 1 to n are present, then smallest element that is missing will be n + 1. 
} 

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << missingNumber_one(arr, n) << endl; //approach 1
    cout << missingNumber_two(arr, n) << endl; //approach 2
}