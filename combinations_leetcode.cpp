#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
    void solve(int i, int n, vector<int>& ans, vector<int>& temp, int k){
        bitset<32> b(i);
        for(int i = 0; i < n; i++){
            if(b[i]){
                temp.push_back(ans[i]);
            }
        }
        if(temp.size() == k){
            res.push_back(temp);
        }
    }
    vector<vector<int>> combine(int n, int k){
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = i + 1;
        }
        int mask = (1<<n) - 1;
        for(int i = 1; i <= mask; i++){
            vector<int> temp;
            solve(i, n, ans, temp, k);
        }
        return res;
    }

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> result = combine(n, k);
    for(auto it : result){
        cout << "[";
        for(auto i : it){
            cout << i << ",";
        }
        cout << "]";
    }
}