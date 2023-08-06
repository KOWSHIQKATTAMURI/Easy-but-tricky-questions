//https://leetcode.com/contest/weekly-contest-357/problems/check-if-it-is-possible-to-split-array/

#include<bits/stdc++.h>
using namespace std;

bool canSplitArray(vector<int> &nums, int m){
    if(nums.size() <= 2){
        return true;
    }
    for(int i = 0; i < nums.size() - 1; i++){
        if(nums[i] + nums[i + 1] >= m){
            return true;
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(auto &i : nums){
        cin >> i;
    }
    cout << canSplitArray(nums, m) << endl;
}