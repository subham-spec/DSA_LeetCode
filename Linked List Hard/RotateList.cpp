#include "Node.cpp"

int findLength(Node* head) {
        int count = 0;
        while(head) {
            head = head->next;
            ++count;
        }
        return count;
    }
    Node* rotateRight(Node* head, int k) {
        if(!head)
            return head;
        int len = findLength(head);
        k = k%len;

        Node* slow = head;
        Node* fast = head;
        while(k){
            fast = fast->next;
            --k;
        }
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;

        return head;
    }