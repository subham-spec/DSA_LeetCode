#include "Node.cpp"
#include <iostream>
#include <queue>
#include <map>

using namespace std;

vector<vector<int>> verticalTraversal(Node* root) {
        queue<pair<Node*, pair<int, int>>> q;
        q.push({root, {0,0}});
        map<int, map<int, multiset<int>>> mp;
        Node* node;
        int i, j;
        
        while(!q.empty()) {
            node = q.front().first;
            i = q.front().second.first;
            j = q.front().second.second;
            q.pop();

            if(node->left)
                q.push({node->left, {i-1, j+1}});
            if(node->right)
                q.push({node->right, {i+1, j+1}});

            mp[i][j].insert(node->data);
        }

        vector<vector<int>> ans;
        for(auto i: mp) {
            vector<int> arr;
            for(auto j: i.second) {
                arr.insert(arr.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(arr);
        }
        return ans;
    }