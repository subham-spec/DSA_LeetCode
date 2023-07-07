#include "Node.cpp"
#include <cmath>
#include <iostream>
#include <algorithm>

int findDiff(Node* root){
        if(root == nullptr)
            return 0;
        int left = findDiff(root->left);
        int right = findDiff(root->right);

        if(left == -1 || right == -1 || abs(left-right)>1)
            return -1;
        return 1 + max(left, right);
    }
    bool isBalanced(Node* root) {
        int ans = 0;
        ans = findDiff(root);
        return true ? ans>=0 : false;
    }