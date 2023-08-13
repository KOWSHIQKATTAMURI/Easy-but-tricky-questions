//https://www.codingninjas.com/studio/problems/majority-element_842495?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

int majority_element(vector<int> &nums){
    int n = nums.size(), count = 0;
    int majority;
    for(int i = 0; i < n; i++){
        if(count == 0){
            majority = nums[i];
            count++;
        }else{
            if(nums[i] == majority){
                count++;
            }else{
                count--;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == majority){
            ans++;
        }
    }
    return ans > n/2 ? majority : -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &i : nums){
        cin >> i;
    }
    cout << majority_element(nums) << endl;
}