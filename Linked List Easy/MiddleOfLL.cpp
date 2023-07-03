#include <iostream>
#include "Node.cpp";
using namespace std;

Node* middleNode(Node* head) {
        Node* h1 = head;
        Node* h2 = head;

        while(h2 && h2->next){
            h2 = h2->next->next;
            h1 = h1->next;
        }
        return h1;
    }