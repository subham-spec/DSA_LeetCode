#include "Node.cpp"
#include <map>
#include <queue>
using namespace std;

void markParents(map<Node*, Node*>& parents, Node* root, Node* parent) {
        if(!root)
            return;
        parents[root] = parent;
        markParents(parents, root->left, root);
        markParents(parents, root->right, root);
    }
    Node* searchStart(Node* root, int start) {
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            if(front->data == start)
                return front;
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        return NULL;
    }
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> parents;
        markParents(parents, root, NULL);
    
        Node* start = searchStart(root, target);
        
        int count = 0;
        queue<Node*> q;
        map<Node*, bool> vis;
        q.push(start);
        vis[start] = true;
        Node* node;
        
        while(!q.empty()) {
            count++;
            int size = q.size();
            for(int i=0; i<size; i++) {
                node = q.front();
                q.pop();
                if(node->left && !vis[node->left]) {
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right]) {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if(parents[node] && !vis[parents[node]]) {
                    q.push(parents[node]);
                    vis[parents[node]] = true;
                }
            }
        }
        
        return count-1;
    }