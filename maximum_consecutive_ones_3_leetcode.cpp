//https://leetcode.com/problems/max-consecutive-ones-iii/description/

#include<bits/stdc++.h>
using namespace std;

int max_ones(vector<int>& nums, int k){
    int left = 0, n = nums.size(), zeros = 0;
    for(int right = 0; right < nums.size(); right++){
        if(!nums[right]){
            //as soon as we encounter a zero, we increase the count of zeros by one.
            zeros++;
            //if number of zeros is greater than k, then we shrink the window till we the number of zeros is equal to k.
            while(zeros > k){
                //shrinking is done from left to right
                if(!nums[left]){
                    zeros--;
                }
                left++;
            }
        }
        //after every successful computation, we update the ans to the maximum value possible.
        ans = max(ans, right - left + 1);
    }
    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(auto &i : nums){
        cin >> i;
    }
    cout << max_ones(nums, k) << endl;
}