#include<bits/stdc++.h>
using namespace std;

long long int mod = 1e9 + 7;
long long int solve(vector<vector<long long int>>& dp, int oi, int ni, int n, int m, string on, string nn){
    if(ni >= m){
        return 1;
    }
    if(oi >= n){
        return 0;
    }
    if(dp[oi][ni] != -1){
        return dp[oi][ni];
    }
    long long int take = 0;
    if(on[oi] == nn[ni]){
        take += solve(dp, oi + 1, ni + 1, n, m, on, nn)%mod;
    }
    long long int not_take = solve(dp, oi + 1, ni, n, m, on, nn)%mod;
    return dp[oi][ni] = (take%mod + (not_take)%mod)%mod;
}

int numDistinct_dp(string &oldName, string &newName){
    int n = oldName.size(), m = newName.size();
    vector<vector<long long int>> dp(n, vector<long long int>(m, -1));
    long long int ans = solve(dp, 0, 0, n, m, oldName, newName)%mod;
    return (int)ans;
}

int numDistinct_tabulation(string &oldName, string &newName){
    int m = oldName.length(), n = newName.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    //if newName string is an empty string, then any length of oldname string will be a valid answer.
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            //either proceed forward by omitting the matched characters both in oldName and newName
            //or omit the matched character in oldname string and move forward. 
            if(oldName[i - 1] == newName[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
} 

int main(){
    //s1 -> oldname, s2 -> newname
    string s1, s2;
    cin >> s1 >> s2;
    cout << numDistinct_dp(s1, s2) << endl;
    cout << numDistinct_tabulation(s1, s2) << endl;
}