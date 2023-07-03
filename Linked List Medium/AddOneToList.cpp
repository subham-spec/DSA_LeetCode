#include "Node.cpp"
int mergeOne(Node* head, int rem) {
        if(head->next == nullptr) {
            if(head->val+rem > 9) {
                head->val = 0;
                return 1;
            }
            else {
                head->val++;
                return 0;
            }
        }
        int result = mergeOne(head->next, 1);
        if(result == 0)
            return 0;
        else {
            if(result+head->val > 9){
                head->val = 0;
                return 1;
            }
            else{
                head->val += result;
                return 0;
            }
        }
    }
    Node* addOne(Node *head) 
    {
        int result = mergeOne(head, 1);
        if(result) {
            Node* hdd = new Node(1);
            hdd->next = head;
            return hdd;
        }
        else 
            return head;
    }