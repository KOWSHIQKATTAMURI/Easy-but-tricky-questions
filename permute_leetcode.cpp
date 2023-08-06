#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int> &temp, vector<bool> status){
        if(nums.size() == temp.size()){
            ans.push_back(temp);
        }
        for(int i = 0; i < nums.size(); i++){
            if(!status[i]){
                temp.push_back(nums[i]);
                status[i] = true;
                solve(nums, ans, temp, status);
                temp.pop_back();
                status[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> status(nums.size());
        solve(nums, ans, temp, status);
        return ans;
    }

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &i : nums){
        cin >> i;
    }
    vector<vector<int>> ans = permute(nums);
    for(auto it : ans){
        for(auto i : it){
            cout << i << " ";
        }
        cout << endl;
    }
}