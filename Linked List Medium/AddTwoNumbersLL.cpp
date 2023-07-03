#include "Node.cpp"
void addNumber(Node* ans, Node* a, Node* b, int rem){
        if(!a && !b){
            if(rem == 1){
                ans->next = new Node(1);
            }
            return;
        }
        int sum;
        if(!a) {
            sum = b->val + rem;
            ans->next = new Node(sum%10);
            addNumber(ans->next, a, b->next, sum/10);
        }
        else if(!b) {
            sum = a->val + rem;
            ans->next = new Node(sum%10);
            addNumber(ans->next, a->next, b, sum/10);
        }
        else{
            sum = a->val + b->val + rem;
            ans->next = new Node(sum%10);
            addNumber(ans->next, a->next, b->next, sum/10);
        }
    }
    Node* addTwoNumbers(Node* l1, Node* l2) {
        Node* ans = new Node(-1);
        addNumber(ans, l1, l2, 0);

        return ans->next;
    }