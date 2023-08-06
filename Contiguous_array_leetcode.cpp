//https://leetcode.com/problems/contiguous-array/

#include<bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums){
        int longest_sum = 0, sum = 0;
        unordered_map<int, int> kow;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i] == 1 ? 1 : -1; //assuming 0 to equal to -1
            if(sum == 0){
                if(longest_sum < i + 1){
                    longest_sum = i + 1;
                }
            }else if(kow.find(sum) != kow.end()){ //if the same sum is encountered again, then the present length is i - kow[sum] (kow[sum] gives the index of the same sum that previously/first appered)
                if(longest_sum < i - kow[sum]){
                    longest_sum = i - kow[sum];
                }
            }else{
                kow[sum] = i;
            }
        }
        return longest_sum;
    }

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& i : nums){
        cin >> i;
    }
    cout << findMaxLength(nums);
}
