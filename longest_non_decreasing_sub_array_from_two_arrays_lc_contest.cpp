#include<bits/stdc++.h>
using namespace std;

//approach 1
//extra space
int maxNonDecreasingLength_one(vector<int>& nums1, vector<int>& nums2){
    int n = nums1.size();
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = 1, dp[0][1] = 1; //dp[0][0] -> 0th index in nums1, dp[0][1] -> 0th index in nums2
    int ans = 1;
    //there are total of four cases:
    //1)if the present ith index element in nums1 is greater than (i - 1)th index element in nums1 -> then add 1 to dp[i - 1][0]
    //2)if the present ith index element in nums1 is greater than (i - 1)th index element in nums2 -> take max(present state, dp[i - 1][1] + 1)
    //3)if the present ith index element in nums2 is greater than (i - 1)th index element in nums1 -> then add 1 to dp[i - 1][1]
    //4)if the present ith index element in nums2 is greater than (i - 1)th index element in nums2 -> take max(present state, dp[i - 1][0] + 1)
    for(int i = 1; i < n; i++){
        dp[i][0] = 1, dp[i][1] = 1;
        if(nums1[i] >= nums1[i - 1]){
            dp[i][0] = dp[i - 1][0] + 1;
        }
        if(nums1[i] >= nums2[i - 1]){
            dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
        }
        if(nums2[i] >= nums2[i - 1]){
            dp[i][1] = dp[i - 1][1] + 1;
        }
        if(nums2[i] >= nums1[i - 1]){
            dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
        }
        ans = max({ans, dp[i][0], dp[i][1]});
    }
    return ans;
}

//approach 2
//No extra space
int maxNonDecreasingLength_two(vector<int>& nums1, vector<int>& nums2){
    int n = nums1.size();
    vector<int> a(2, 1); //instead of n size, two size is enough as we are only dependent on (i - 1)th values
    int ans = 1;
    for(int i = 1; i < n; i++){
        vector<int> b(2, 1);
        if(nums1[i] >= nums1[i - 1]){
            b[0] = a[0] + 1;
        }
        if(nums1[i] >= nums2[i - 1]){
            b[0] = max(b[0], 1 + a[1]);
        }
        if(nums2[i] >= nums2[i - 1]){
            b[1] = a[1] + 1;
        }
        if(nums2[i] >= nums1[i - 1]){
            b[1] = max(b[1], 1 + a[0]);
        }
        ans = max({ans, b[0], b[1]});
        a = b;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums1(n), nums2(n);
    for(auto &i : nums1){
        cin >> i;
    }
    for(auto &i : nums2){
        cin >> i;
    }
    cout << maxNonDecreasingLength_one(nums1, nums2) << endl; //approach 1
    cout << maxNonDecreasingLength_two(nums1, nums2) << endl; //approach 2
}