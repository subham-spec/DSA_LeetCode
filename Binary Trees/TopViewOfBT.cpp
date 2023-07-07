#include "Node.cpp"
#include <iostream>
#include <map>
#include <queue>
using namespace std;

vector<int> topView(Node *root) {
        vector<int> ans;
        if(!root)
            return ans;
            
        map<int, int> mp;
        queue<pair<int, Node*>> q;
        q.push({0, root});
    
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                Node* node = q.front().second;
                int idx = q.front().first;
                
                q.pop();
                if(mp.find(idx) == mp.end())
                    mp[idx] = node->data;
                
                if(node->left)
                    q.push({idx-1, node->left});
                if(node->right)
                    q.push({idx+1, node->right});
            }
        }
        
        for(auto i: mp) {
            ans.push_back(i.second);
        }
        return ans;
    }