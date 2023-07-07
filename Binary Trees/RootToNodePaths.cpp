#include "Node.cpp"
#include <iostream>
using namespace std;

void findPaths(Node* root, vector<int>& curr, vector<vector<int>>& ans) {
    if(!root->left && !root->right) {
        curr.push_back(root->data);
        ans.push_back(curr);
        curr.pop_back();
        return;
    }
    curr.push_back(root->data);
    if(root->left)
        findPaths(root->left, curr, ans);
    if(root->right)
        findPaths(root->right, curr, ans);
    
    curr.pop_back();
    return;
}

vector<vector<int>> Paths(Node* root) {
    vector<vector<int>> ans;
    if(!root)
        return ans;
    vector<int> curr;
    
    findPaths(root, curr, ans);
    return ans;
}