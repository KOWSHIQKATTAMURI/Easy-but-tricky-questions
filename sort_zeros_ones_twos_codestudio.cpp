//https://www.codingninjas.com/studio/problems/sort-0-1-2_631055

#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int> &nums){
    int current = 0, zeroPos = 0, twoPos = nums.size() - 1;
    while(current <= twoPos){
        if(nums[current] == 0){
            swap(nums[current], nums[zeroPos]);
            current++;
            zeroPos++;
        }else if(nums[current] == 2){
            swap(nums[current], nums[twoPos]);
            twoPos--;
        }else{
            current++;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort012(nums);
    for(auto i : nums){
        cout << i << " ";
    }
}