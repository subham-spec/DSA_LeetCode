#include "Node.cpp"
#include <vector>
using namespace std;

bool isLeaf(Node* root) {
    if(!root->left && !root->right)
        return true;
    return false;
}
void getLeftTree(Node* root, vector<int>& left) {
    if(!root)
        return;
    if(!isLeaf(root))
        left.push_back(root->data);
    else 
        return;
        
    if(root->left)
        getLeftTree(root->left, left);
    else
        getLeftTree(root->right, left);
    return;
}
void getLeafNodes(Node* root, vector<int>& leaf) {
    if(!root)
        return;
    if (isLeaf(root)) {
        leaf.push_back(root->data);
        return;
    }
    if(root->left)
        getLeafNodes(root->left, leaf);
    if(root->right)
        getLeafNodes(root->right, leaf);
    return;
}
void getRightTree(Node* root, vector<int>& right) {
    if(!root)
        return;
    if(!isLeaf(root))
        right.push_back(root->data);
    else
        return;
    if(root->right)
        getRightTree(root->right, right);
    else    
        getRightTree(root->left, right);
    return;
}
vector<int> traverseBoundary(Node* root){
    // Write your code here.
    vector<int> left;
    vector<int> leaves;
    vector<int> right;
    
    if(!isLeaf(root)) {
        left.push_back(root->data);
    }
    getLeftTree(root->left, left);
    getLeafNodes(root, leaves);
    getRightTree(root->right, right);
    vector<int> ans;
    
    for(int i=0; i<left.size(); i++)
        ans.push_back(left[i]);

    for(int i=0; i<leaves.size(); i++)
        ans.push_back(leaves[i]);
    
    for(int i=right.size()-1; i>=0; i--)
        ans.push_back(right[i]);
    
    return ans;
}

int findMaxWidth(Node* root) {
    int maxi = 0;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    pair<Node*, int> node;

    while(!q.empty()){
        int n = q.size();
        int start = q.front().second;
        int end = q.back().second;

        maxi = max(maxi, end-start+1);
        for(int i=0; i<n; i++){
            node = q.front();
            q.pop();

            Node *first = node.first;
            int second = node.second;

            if(first->left)
                q.push({first->left, 2*second+1});
            if(first->right)
                q.push({first->right, 2*second+2});
        }
    }

    return maxi;
}