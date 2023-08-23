//https://practice.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1

#include<bits/stdc++.h>
using namespace std;    

int findMinOperation(vector<vector<int>>& matrix, int n){
    int max_sum = 0, ans = 0;
    //calculating maximum possible row sum
    for(int i = 0; i < n; i++){
        int row_sum = 0;
        for(int j = 0; j < n; j++){
            row_sum += matrix[i][j];
        }
        max_sum = max(max_sum, row_sum);
    }
    //calculating maximum possible column sum
    for(int j = 0; j < n; j++){
        int col_sum = 0;
        for(int i = 0; i < n; i++){
            col_sum += matrix[i][j];
        }
        max_sum = max(max_sum, col_sum);
    }
    //choose column wise or row wise. Here column wise has been choosen
    for(int j = 0; j < n; j++){
        int col_sum = 0;
        for(int i = 0; i < n; i++){
            col_sum += matrix[i][j];
        }
        //these are the number of operations that need to be performed on that column to reach maximum sum
        ans += (max_sum - col_sum);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    cout << findMinOperation(matrix, n) << endl;
}