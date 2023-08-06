#include<bits/stdc++.h>
using namespace std;

unordered_set<string> st;
unordered_map<string, bool> dp;
bool solve(string s){
    if(s.length() == 0){
        return true;
    }
    if(dp.find(s) != dp.end()){
        return dp[s];
    }
    for(int i = 0; i < s.length(); i++){
        //s.substr(0, i + 1) denotes the string starting with index 0 and of length i + 1.
        //s.substr(i + 1) denotes the string starting with index i + 1 and of its full length.
        if(st.count(s.substr(0, i + 1)) and solve(s.substr(i + 1))){
            return dp[s] = true;
        }
    }
    return dp[s] = false;
}
bool wordBreak(string s, vector<string>& wordDict){
    for(auto word : wordDict){
        st.insert(word);
    }
    return solve(s);
}

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> worddic(n);
    for(auto &word : worddic){
        cin >> word;
    }
    cout << wordBreak(s, worddic) << endl;
}