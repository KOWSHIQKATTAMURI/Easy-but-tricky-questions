//https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1


#include<bits/stdc++.h>
using namespace std;

void deleting(stack<int>& s, int n, int &index){
    if(index == (n - (ceil((n + 1)/2)))){
        s.pop();
        return;
    }
    int start = s.top();
    s.pop();
    index += 1; 
    deleting(s, n, index); //cannot write index + 1 as there is an ampersand to index
    s.push(start);
}
void deleteMid(stack<int>&s, int sizeOfStack){
    int n = sizeOfStack, index = 0;
    deleting(s, n, index);
}

int main(){
    int n;
    cin >> n;
    stack<int> s;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        s.push(a);
    }
    deleteMid(s, n);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}