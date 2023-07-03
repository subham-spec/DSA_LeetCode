#include <iostream>
#include "Node.cpp"
using namespace std;

Node* reverseList(Node* head){
        Node* prev = NULL;
        while(head){
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(Node* head) {
        Node* slow = head;
        Node* fast = head;

        if(!fast->next)
            return true;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* temp = reverseList(slow);
        slow = head;

        while(temp){
            cout<<temp->val<<' '<<slow->val<<endl;
            if(temp->val != slow->val)
                return false;
            temp = temp->next;
            slow = slow->next;
        }
        return true;
    }