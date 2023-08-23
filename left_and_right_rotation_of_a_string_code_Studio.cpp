//https://www.codingninjas.com/studio/problems/left-and-right-rotation-of-a-string_840707?leftPanelTab=2

#include<bits/stdc++.h>
using namespace std;

string leftRotate(string s, int d){
    int n = s.length();
    if(n < d){
        return leftRotate(s, d%n);
    }
    //first reverse (d length) component from the beginning.
    //then reverse (n - d) length component from the dth index.
    //then reverse the whole string.
    //this gives the final string, which is obtained by rotating d units to the left of the original string.
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
    return s;
}

string rightRotate(string s, int d){
    int n = s.length();
    if(n < d){
        return rightRotate(s, d%n);
    }
    //right rotation is nothing but (n - d) units left rotation
    string ans = leftRotate(s, n - d);
    return ans;
}

int main(){
    string s;
    int d;
    cin >> s;
    cin >> d;
    cout << leftRotate(s, d) << endl;
    cout << rightRotate(s, d) << endl;
}