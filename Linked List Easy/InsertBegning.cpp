#include <iostream>
#include "Node.cpp";
using namespace std;

Node *insertAtBegining(Node *head, int x) {
    // Your code here
    if(head == NULL)
        return new Node(x);
    Node* temp = new Node(x);
    temp->next = head;
    return temp;
}