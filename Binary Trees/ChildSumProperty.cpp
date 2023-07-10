#include "Node.cpp"
bool isLeaf(Node* root) {
        if(!root->left && !root->right)
            return true;
        return false;
    }
    int isSumProperty(Node *root)
    {
     // Add your code here
        if(!root || isLeaf(root))
            return 1;
            
        int l = 0;
        if(root->left)
            l += root->left->data;
        if(root->right)
            l += root->right->data;
        
        // cout<<l<<endl;
        if(root->data != l) {
            return 0;
        }
        return isSumProperty(root->left) && isSumProperty(root->right);
    }