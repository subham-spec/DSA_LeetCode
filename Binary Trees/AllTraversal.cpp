#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

void preOrder(Node* root) {
    if(!root)
        return;
    cout<<root->data<<' ';
    preOrder(root->left);
    preOrder(root->right);
}
void PreOrder(Node* root) {
    stack<Node*> s;
    s.push(root);
    while(!s.empty()) {
        Node* node = s.top();
        cout<<node->data<<' ';
        s.pop();
        if(node->right)
            s.push(node->right);
        if(node->left)
            s.push(node->left);
    }
}

void inOrder(Node* root) {
    if(!root)
        return;
    inOrder(root->left);
    cout<<root->data<<' ';
    inOrder(root->right);
}

void InOrder(Node* root) {
    stack<Node*> s;
    s.push(root);
    while(!s.empty()) {
        Node* top = s.top();
        if(top == NULL) {
            s.pop();
            if(s.empty())
                break;
            top = s.top();
            s.pop();
            cout<<top->data<<' ';
            s.push(top->right);
        } else {
            s.push(top->left);
        }
    }
}

void PostOrder(Node* root) {
    Node* curr = root;
    stack<Node*> s;

    while(curr || !s.empty()) {
        if(curr) {
            s.push(curr);
            curr = curr->left;
        } else {
            Node* temp = s.top()->right;
            if(temp == NULL) {
                temp = s.top();
                s.pop();
                cout<<temp->data<<' ';
                while(!s.empty() && temp == s.top()->right){
                    temp = s.top();
                    s.pop();
                    cout<<temp->data<<' ';
                }
            } else {
                curr = temp;
            }
        }
    }
}

void levelOrder(Node* root) {
    if(!root)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; i++){
            Node* temp = q.front();
            q.pop();
            cout<<temp->data<<' ';
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return;
}