#include "Node.cpp"
#include <bits/stdc++.h>
#include <pair>

Node* findLast(Node* head) {
        while(head->next) {
            head = head->next;
        }
        return head;
    }
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> ans;
        Node* last = findLast(head);
        Node* start = head;
        
        
        // looping for two pointer
        while (start->data < last->data) {
            int sum = start->data+last->data;
            if(sum == target){
                ans.push_back({start->data, last->data});
                start = start->next;
                last = last->prev;
            }
            else if(sum < target)
                start = start->next;
            else
                last = last->prev;
        }
        
        return ans;
    }