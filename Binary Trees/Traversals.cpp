#include <iostream>
#include "AllTraversal.cpp"

using namespace std;

int main() {
    Node* root = new Node(7);
    //left side part
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    root->left->right->left = new Node(1);

    // right side part
    root->right = new Node(6);
    root->right->right = new Node(8);

    /*
            7
           / \
          5   6
         / \   \
        4   2   8
           /
          1
    */

    cout<<"The pre-order traversal of the tree with recursion is:\n";
    preOrder(root);
    cout<<"\n\n";
    
    cout<<"The pre-order traversal of the tree is:- ";
    PreOrder(root);
    cout<<"\n\n";

    cout<<"The In-order traversal of the tree with recursion is:- ";
    inOrder(root);
    cout<<"\n\n";

    cout<<"The In-order traversal of the tree is:- ";
    InOrder(root);
    cout<<"\n\n";

    cout<<"The Post-order traversal of the tree is:- ";
    PostOrder(root);
    cout<<"\n\n";

    cout<<"The Level-order traversal of the tree is:- ";
    levelOrder(root);
    cout<<"\n\n";
}