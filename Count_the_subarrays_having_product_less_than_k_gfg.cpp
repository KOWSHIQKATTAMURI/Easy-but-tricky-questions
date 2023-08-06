//https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1

#include<bits/stdc++.h>
using namespace std;

long long countSubArrayProductLessThanK(vector<int>& nums, long long k){
    int i = 0, j = 0, n = nums.size();
    long long product = 1, count = 0;
    while(j < n){ //sliding windown
        product *= nums[j];
        while(i <= j and product >= k){ 
            product /= nums[i];
            i++;
        }
        count += j - i + 1; //to count all the subarrays possible in that range
        j++;
    }
    return count;
}

int main(){
    int n;
    long long k;
    cin >> n >> k;
    vector<int> nums(n);
    for(auto &i : nums){
        cin >> i;
    }
    cout << countSubArrayProductLessThanK(nums, k) << endl;
}