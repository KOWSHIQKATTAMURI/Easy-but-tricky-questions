//https://leetcode.com/problems/counting-bits/?envType=daily-question&envId=2023-09-01

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    //Approach 1
    //T.C -> O(nlogn) (time taken to count bits in a number x is logx)
    vector<int> ans_one(n + 1, 0);
    for(int i = 1; i <= n; i++){
        ans_one[i] = __builtin_popcount(i);
    }
    //Approach 2
    //T.C -> O(n)
    vector<int> ans_two(n + 1, 0);
    for(int i = 1; i <= n; i++){
        ans_two[i] = ans_two[i/2] + i%2;
    }
    for(int i = 1; i <= n; i++){
        cout << ans_one[i] << " ";
    }
    cout << endl;
    for(int i = 1; i <= n; i++){
        cout << ans_two[i] << " ";
    }
}
