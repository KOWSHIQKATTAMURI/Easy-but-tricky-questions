//https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1

#include<bits/stdc++.h>
using namespace std;

vector<int> dx = {-1, 1, 0, 0, -1, -1, 1, 1}, dy = {0, 0, -1, 1, 1, -1, 1, -1};

bool is_valid(int x, int y, vector<vector<char>>& grid, char ch){
    if(x >= 0 and y >= 0 and x < grid.size() and y < grid[0].size() and grid[x][y] == ch){
        return true;
    }
    return false;
}

bool find(int x, int y, vector<vector<char>>& grid, string& word){
    //total of 8 directions
    for(int k = 0; k < 8; k++){
        //'i' is used to count the characters we succesfully found
        int i = 1, nx = x + dx[k], ny = y + dy[k];
        for(; i < word.length(); i++){
            if(!is_valid(nx, ny, grid, word[i])){
                break;
            }
            //continuing in that specific direction
            nx += dx[k], ny += dy[k];
        } 
        if(i == word.length()){
            return true;
        }
    }
}

vector<vector<int>> searchWord(vector<vector<char>>& grid, string word){
    vector<vector<int>> ans;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == word[0]){
                if(find(i, j, grid, word)){
                    ans.push_back({i, j});
                }
            }
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    string word;
    cin >> word;
    vector<vector<int>> ans = searchWord(grid, word);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
} 