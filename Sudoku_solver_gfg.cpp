#include<bits/stdc++.h>
using namespace std;

int N;

bool isValid(vector<vector<int>> &grid, int row, int col, int val){
     for(int i = 0; i < 9; i++){
            if(grid[i][col] == val){
                return false;
            }
            if(grid[row][i] == val){
                return false;
            }
            if(grid[3*(row/3) + i/3][3*(col/3) + i%3] == val){
                return false;
            }
        }
        return true;
    }
    bool SolveSudoku(vector<vector<int>> &grid){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 0){
                    for(int k = 1; k <= 9; k++){
                        if(isValid(grid, i, j, k)){
                            grid[i][j] = k;
                            if(SolveSudoku(grid)){
                                return true;
                            }else{
                                grid[i][j] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void printGrid(vector<vector<int>> &grid){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << grid[i][j] << " ";
            }
        }
    }

int main(){
    int n;
    cin >> n;
    N = n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> grid[i][j];
        }
    }
    if(SolveSudoku(grid)){
        printGrid(grid);
    }else{
        cout << "No Sol" << endl;
    }
    return 0;
}