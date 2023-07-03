#include "Node.cpp"
Node* deleteMiddle(Node* head) {
        if(!head->next)
            return nullptr;
        
        Node* slow = head;
        Node* fast = head->next->next;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;

        return head;
    }