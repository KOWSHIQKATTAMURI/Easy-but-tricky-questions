//https://practice.geeksforgeeks.org/problems/maximum-index3307/1

#include<bits/stdc++.h>
using namespace std;

int maxIndexDiff(vector<int>& arr){
        int n = arr.size(), i = 0, j = n - 1, ans = 0;
        while(i < j){ //starting from end of the array
            if(arr[i] <= arr[j]){ //if arr[j] is greater than arr[i] then update the ans
                ans = max(ans, j - i); 
                i++; //done with the ith element, so i++
                j = n - 1; //again equating j to the end of the array
            }else{
                j--; //if arr[i] is not less than arr[j] then go to the left of the array
            }
        }
        return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr){
        cin >> i;
    }
    cout << maxIndexDiff(arr) << endl;
}