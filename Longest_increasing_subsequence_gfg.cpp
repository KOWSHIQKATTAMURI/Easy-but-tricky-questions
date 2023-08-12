#include<bits/stdc++.h>
using namespace std;

//T.C -> O(n^2)
int longestsubsequence_usingdp(vector<int>& nums){
    vector<int> dp(nums.size(), 1);
    int ans = 0;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i - 1; j >= 0; j--){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

//T.C -> O(nlog(n))
int longestsubsequence_usinglowerbound(vector<int>& nums){
    vector<int> res;
    for(auto it : nums){
        auto at = lower_bound(res.begin(), res.end(), it);
        if(at == res.end()){
            res.push_back(it);
        }else{ 
            //if a number just greater than or equal to it is already there in res, then we replace it with it.
            //we need to remember that we are only bothered about the length of the longest sequence but not with the elements
            res[at - res.begin()] = it;
        }
    }
    return res.size();
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &i : nums){
        cin >> i;
    }
    cout << longestsubsequence_usingdp(nums) << endl;
    cout << longestsubsequence_usinglowerbound(nums) << endl;
}