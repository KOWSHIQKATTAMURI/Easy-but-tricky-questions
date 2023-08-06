#include<bits/stdc++.h>
using namespace std;

//bottom up dp
int maximumJumps(vector<int>& nums, int target){
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = 0; //dp[0] is equal to number of ways of reaching zeroth index
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(abs(nums[j] - nums[i]) <= target and dp[j] != -1){
                if(dp[i] == -1){ //if dp[i] == -1, that means it has not been evaluated yet
                    dp[i] = dp[j] + 1; 
                }else{ //it if not equal to -1, then it should be updated to the maximum of (present value, dp[j] + 1).
                    dp[i] = max(dp[i], dp[j] + 1); 
                }
            }
        }
    }
    return dp[n - 1]; //dp[n - 1] is equal to number of ways of reaching (n - 1)th index.
}

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(auto &i : nums){
        cin >> i;
    }
    cout << maximumJumps(nums, target) << endl;
}