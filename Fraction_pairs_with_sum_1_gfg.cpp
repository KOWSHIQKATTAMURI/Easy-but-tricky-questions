#include<bits/stdc++.h>
using namespace std;

int countFractions(vector<int>& numerator, vector<int>& denominator){
    int count = 0;
    //unordered map cannnot be used to store pairs.
    map<pair<int, int>, int> mp;
    for(int i = 0; i < numerator.size(); i++){
        int num = numerator[i];
        int den = denominator[i];
        int hcf = __gcd(numerator[i], denominator[i]);
        //dividing by hcf leads to the simplified fraction.
        num /= hcf, den /= hcf;
        //if we have our present fraction as 2/7, then we need to search for (7 - 2)/7, as 2/7 + 5/7 = 1.
        if(mp.find({den - num, den}) != mp.end()){
            count += mp[{den - num, den}];
        }
        mp[{num, den}]++;
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int> numerator(n), denominator(n);
    for(auto &i : numerator){ 
        cin >> i;
    }
    for(auto &i : denominator){  
        cin >> i;
    }
    cout << countFractions(numerator, denominator) << endl;
}