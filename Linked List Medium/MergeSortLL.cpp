#include "Node.cpp"
Node* findMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* merge(Node* left, Node* right) {
        if(!left)
            return right;
        if(!right)
            return left;
        
        Node* temp = new Node(-1);
        Node* ans = temp;

        while(left && right){
            if(left->val < right->val){
                temp->next = left;
                temp = temp->next;
                left = left->next;
            } else {
                temp->next = right;
                temp = temp->next;
                right = right->next;
            }
        }

        while(left) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while(right) {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        return ans->next;
    }

    Node* sortList(Node* head) {
        if(!head || !head->next)
            return head;

        // Finding the mid of the linked list
        Node* mid = findMid(head);
        Node* left = head;
        Node* right = mid->next;
        mid->next = nullptr;

        // breaking the list into two halfs
        left = sortList(left);
        right = sortList(right);

        // merging the list
        Node* result = merge(left, right);
        return result;
    }