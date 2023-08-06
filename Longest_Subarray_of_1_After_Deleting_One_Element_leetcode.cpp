//https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums){
    int i = 0, j = 0, n = nums.size(), last_index = -1, max_length = 0, count_zeros = 0; //last_index is for storing the previously encountered zero index
    while(j < n){
        if(nums[j] == 0){
            i = last_index + 1; //shrinking the window
            last_index = j; 
        }
        max_length = max(max_length, j - i); //finding maximum length of the window
        j++;
    }
    return max_length;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto&i : nums){
        cin >> i;
    }
    cout << longestSubarray(nums) << endl;
}

//Main logic here is to use sliding window so that we can have atmost one zero in the subarray we considered.
//If we encounter the second zero then we will shrink the window till we omit the first zero.