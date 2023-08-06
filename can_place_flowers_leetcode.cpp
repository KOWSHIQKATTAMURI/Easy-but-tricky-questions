//https://leetcode.com/problems/can-place-flowers/description/

#include<bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n){
    if(n == 0){
       return true;
    }
    for(int i = 0; i < flowerbed.size(); i++){
        if(flowerbed[i] == 0){
            bool left = i == 0 or flowerbed[i - 1] == 0;
            bool right = i == flowerbed.size() - 1 or flowerbed[i + 1] == 0;
            if(left and right){ //to check if both left and right dont have plants
                flowerbed[i] = 1;
                n--; //decresing the number of plants need to be planted by 1
                if(n == 0){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> flowerbed(m);
    for(auto &i : flowerbed){
        cin >> i;
    }
    cout << canPlaceFlowers(flowerbed, n) << endl;
}