#include "Node.cpp"
Node* oddEvenList(Node* head) {
        if(!head)
            return nullptr;
        Node* a = head;
        Node* b = head->next;

        while(b && b->next) {
            Node* temp = a->next;
            a->next = b->next;
            b->next = b->next->next;
            a->next->next = temp;

            a = a->next;
            b = b->next;
        }

        return head;
    }