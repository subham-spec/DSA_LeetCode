#include "Node.cpp"
#include <algorithm>
using namespace std;

int findDiameter(Node* root, int &maxi) {
    if(!root)
        return 0;
    int left = findDiameter(root->left, maxi);
    int right = findDiameter(root->right, maxi);

    if(maxi < left+right)
        maxi = left+right;
    return 1+max(left, right);
}
int diameterOfBinaryTree(Node* root) {
    int maxi = 0;
    findDiameter(root, maxi);
    return 0;
}