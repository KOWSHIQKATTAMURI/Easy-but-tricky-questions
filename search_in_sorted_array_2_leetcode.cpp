#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target){
    int low = 0, high = nums.size() -  1;
    while(low <= high){
        int mid = (low + high)>>1;
        if(nums[mid] == target){
            return true;
        }
        if(nums[mid] == nums[low] and nums[mid] == nums[high]){
            low++, high--;
            continue;
        }
        if(nums[mid] >= nums[low]){
            if(target >= nums[low] and target <= nums[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if(target >= nums[mid] and target <= nums[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return false;
}

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(auto &i : nums){
        cin >> i;
    }
    cout << search(nums, target) << endl;
}