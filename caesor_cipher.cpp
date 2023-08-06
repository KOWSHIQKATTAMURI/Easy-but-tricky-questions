//Codechef starters 97 contest DIV3 2nd question
//https://www.codechef.com/problems/CAESAR?tab=statement

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1000000000000000000
#define MOD 1000000007

void solve(int tc){
    int n;
    cin >> n;
    string a,b,c;
    cin >> a >> b >> c;
    for(int i = 0; i < n; i++){
        cout << (char)('a'+ (b[i] - a[i] + c[i] - 'a' + 26)%26);
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    cin >> tc;
    for(int ttc = 1; ttc <= tc; ttc++)
        solve(ttc);
    return 0;
}