#include<bits/stdc++.h>
using namespace std;

string findUncommonCharacters(string s1, string s2){
    map<char, int> mp;
    for(int i = 0; i < s1.length(); i++){
        if(mp.find(s1[i]) == mp.end()){
            mp.insert({s1[i], 1});
        }
    }
    for(int i = 0; i < s2.length(); i++){
        if(mp.find(s2[i]) == mp.end()){
            mp.insert({s2[i], 2});
        }else{
            if(mp[s2[i]] == 1){
                mp[s2[i]] = -1;
            }
        }
    }
    string ans;
    for(auto it : mp){
        if(it.second == 1 or it.second == 2){
            ans.push_back(it.first);
        }
    }
    return ans;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << findUncommonCharacters(s1, s2) << endl;
}