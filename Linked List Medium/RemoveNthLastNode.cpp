#include "Node.cpp"
Node* removeNthFromEnd(Node* head, int n) {
        int size = 0;
        Node* temp = head;
        while(temp != 0){
            ++size;
            temp = temp->next;
        }
        if(n == size)
            return head->next;
        temp = head;
        while(n-- > 0)
            temp = temp->next;
        Node* temp2 = head;
        while(temp->next != nullptr){
            temp = temp->next;
            temp2 = temp2->next;
        }
        temp2->next = temp2->next->next;
        return head;
    }