class Node {
    public:
        int val;
        Node* next;
        Node(int data){
            this->val = data;
            this->next = nullptr;
        }
};