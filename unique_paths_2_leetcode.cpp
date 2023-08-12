//https://leetcode.com/problems/unique-paths-ii/description/

#include<bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& grid){
    int n = grid.size(), m = grid[0].size();
    vector<int> prev(m, 0);
    for(int i = 0; i < n; i++){
        //basically we are storing the results at each row.
        //we can go to grid[i][j] in (grid[i - 1][j] + grid[i][j - 1]) ways.
        //so instead of a 2d vector, we are storing results in a single vector and updating it after every row (curr = prev).
        vector<int> curr(m, 0);
        for(int j = 0; j < m; j++){
            if(grid[i][j]){
                curr[j] = 0;
            }else if(i == 0 and j == 0){
                curr[j] = 1;
            }else{
                //up is to calculate to see if can come down
                //left is to calculate to see if can come right
                int up = 0, left = 0;
                if(i > 0){
                    up = prev[j];
                }
                if(j > 0){
                    left = curr[j - 1];
                }
                curr[j] = left + up;
            }
        }
        prev = curr;
    }
    return prev[m - 1];
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    cout << uniquePathsWithObstacles(grid) << endl;
}