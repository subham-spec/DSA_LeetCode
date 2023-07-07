#include "Node.cpp"
using namespace std;

bool isSymetric(Node* r1, Node* r2){
        if(r1==nullptr || r2==nullptr)
            return r1 == r2;
        if(r1->data != r2->data)
            return false;
        return isSymetric(r1->left, r2->right) && isSymetric(r1->right, r2->left);
    }
    bool isSymmetric(Node* root) {
        if(root == nullptr)
            return true;
        return isSymetric(root->left, root->right);
    }