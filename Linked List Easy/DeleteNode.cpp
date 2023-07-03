#include "Node.cpp";
void deleteNode(Node* node) {
        node->data = node->next->data;
        Node* next_node = node->next;
        node->next = next_node->next;
        delete(next_node);
    }