#include<bits/stdc++.h>
using namespace std;

//T.C -> O(root(n)), S.C -> O(1)
long long int largestPrimeFactor(int n){
    long long ans = 0;
    for(long long i = 2; i*i <= n; i++){
        while(n%i == 0){
            n = n/i;
        }
        ans = max(ans, i);
    }
    //chance that the final 'n' can also be a prime
    ans = max(ans, (long long)n);
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << largestPrimeFactor(n) << endl;
}