#include "Node.cpp"
int findLength(Node* head){
        int count = 0;
        while(head) {
            ++count;
            head = head->next;
        }
        return count;
    }
    Node *getIntersectionNode(Node *headA, Node *headB) {
        int size_a = findLength(headA);
        int size_b = findLength(headB);

        int diff = 0;
        Node* temp1 = headA;
        Node* temp2 = headB;

        if(size_a < size_b){
            diff = size_b - size_a;
            temp1 = headB;
            temp2 = headA;
        } else {
            diff = size_a - size_b;
        }
        
        while(diff) {
            temp1 = temp1->next;
            --diff;
        }
        if(temp1 == temp2)
            return temp1;

        while(temp1 && temp2) {
            if(temp1->next == temp2->next)
                return temp1->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return nullptr;
    }