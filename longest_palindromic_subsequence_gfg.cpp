#include<bits/stdc++.h>
using namespace std;

int lcs(string &org, string &temp){
    int n = org.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0, dp[0][i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(org[i - 1] == temp[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int longestpalindromesubseq(string &s){
    string org = s;
    reverse(s.begin(), s.end());
    string temp = s;
    return lcs(org, temp);
}

int main(){
    string s;
    cin >> s;
    cout << longestpalindromesubseq(s) << endl;
}