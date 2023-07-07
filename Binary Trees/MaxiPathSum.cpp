#include "Node.cpp"
#include <algorithm>
using namespace std;

int maxSum(int &maxi, Node* root){
        if(root == nullptr)
            return 0;
        int l = maxSum(maxi, root->left);
        int r = maxSum(maxi, root->right);

        maxi = max(maxi, root->data+l+r);
        return max(l+root->data, max(r+root->data, 0));
    }
    int maxPathSum(Node* root) {
        int maxi = INT_MIN;
        maxSum(maxi, root);
        return maxi;
    }