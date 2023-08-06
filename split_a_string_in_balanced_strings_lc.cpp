#include<bits/stdc++.h>
using namespace std;

int balancedstringsplit(string s){
    int count = 0, ans = 0;
    for(auto &ch : s){
        if(ch == 'R'){
            count++;
        }else{
            count--;
        }
        if(!count){
            ans++;
        }
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << balancedstringsplit(s) << endl;
}