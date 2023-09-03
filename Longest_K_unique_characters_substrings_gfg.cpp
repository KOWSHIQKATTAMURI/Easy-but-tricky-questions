#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string &s, int k){
    int ans = -1, unique = 0, n = s.length();
    vector<int> hash(26);
    for(int left = 0, right = 0; right < n; right++){
        unique += (++hash[s[right] - 'a'] == 1);
        while(unique > k){
            unique -= (--hash[s[left] - 'a'] == 0);
            left++;
        }
        if(unique == k and left <= right){
            ans = max(ans, right - left + 1);
        }
    }
    return ans;
}

int main(){
    int k;
    string s;
    cin >> s >> k;
    cout << longestKSubstr(s, k) << endl;
}