#include "Node.cpp"

Node* reverseKGroup(Node* head, int k) {
        int count = k;
        Node *temp = head;
        while(count && temp){
            temp = temp->next;
            --count;
        }
        if(count == 0){
            Node *prev = nullptr, *curr = head;
            while(curr != temp){
                Node* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head->next = reverseKGroup(temp, k);
            return head = prev;
        }
        else
            return head;
    }