#include<bits/stdc++.h>
using namespace std;

bool findTriplets(int arr[], int n){ //first approach
    sort(arr, arr + n);
    for(int i = 0; i < n; i++){
        int start = arr[i], target = 0 - start;
        int j = i + 1, k = n - 1;
        while(j < k){
            if(arr[j] + arr[k] == target){
                return true;
            }else if(arr[j] + arr[k] < target){
                j++;
            }else{
                k--;
            }
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << findTriplets(arr, n) << endl; 
}