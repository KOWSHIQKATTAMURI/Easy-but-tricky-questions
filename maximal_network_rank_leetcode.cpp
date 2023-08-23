//https://leetcode.com/problems/maximal-network-rank/description/

#include<bits/stdc++.h>
using namespace std;

int maximalnetworkrank(int n, vector<vector<int>> &roads){
    vector<int> degree(n);
    vector<vector<int>> grid(n, vector<int>(n, false));
    for(auto it : roads){
        degree[it[0]]++;
        degree[it[1]]++;
        grid[it[0]][it[1]] = true;
        grid[it[1]][it[0]] = true;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ans = max(ans, degree[j] + degree[i] - grid[i][j]);
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> roads;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        roads.push_back({a, b});
    }
    cout << maximalnetworkrank(n, roads) << endl;
}