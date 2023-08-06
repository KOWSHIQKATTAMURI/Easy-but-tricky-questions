#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {

    }
 };

vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
    //BFS for storing parent of each node starts here
        queue<TreeNode*> p;
        p.push(root);
        unordered_map<TreeNode*, TreeNode*> parent;
        while(!p.empty()){
            TreeNode* start = p.front();
            p.pop();
            if(start -> left){
                parent[start -> left] = start;
                p.push(start -> left);
            }
            if(start -> right){
                parent[start -> right] = start;
                p.push(start -> right);
            }
        }
    //BFS for storing parent of each node ends here 
    //BFS for calculating distance from target node starts here
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        vector<int> ans;
        unordered_map<TreeNode*, bool> visited;
        while(!q.empty()){
            TreeNode* start = q.front().first;
            int dist = q.front().second;
            visited[start] = true;
            if(dist == k){
                ans.push_back(start -> val);
            }
            q.pop();
            if(start -> left and !visited[start -> left]){
                q.push({start -> left, dist + 1});
            }
            if(start -> right and !visited[start -> right]){
                q.push({start -> right, dist + 1});
            }
            if(parent[start] and !visited[parent[start]]){
                q.push({parent[start], dist + 1});
            }
        }
        return ans;
    }

int main(){
    //custom input
    TreeNode *root = new TreeNode(3);
    root -> left = new TreeNode(5);
    root -> right = new TreeNode(1);
    root -> left -> left = new TreeNode(6);
    root -> left -> right = new TreeNode(2);
    root -> left -> right -> left = new TreeNode(7);
    root -> left -> right -> right = new TreeNode(4);
    root -> right -> left = new TreeNode(0);
    root -> right -> right = new TreeNode(8);
    vector<int> result = distanceK(root, root -> left, 2);
    for(auto i : result){
        cout << i << " ";
    }
}