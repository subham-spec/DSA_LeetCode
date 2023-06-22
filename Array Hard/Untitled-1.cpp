#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

struct Node {
    string val;
    vector<Node*> children;
    Node* parent;
    int ancLockCount, decLockCount, uid;
    bool isLocked;

    Node(string value, Node* p) {
        val = value;
        parent = p;
        ancLockCount = 0;
        decLockCount = 0;
        uid = 0;
        isLocked = false;
    }

    void addChildren(const vector<string>& childVals, Node* p) {
        for (const auto& val : childVals)
            children.push_back(new Node(val, p));
    }
};

void printTree(Node* root) {
    cout << "Parent: " << root->val << "\n";
    cout << "Children: \n";
    for (const auto& child : root->children) {
        cout << child->val << " ancLockCount: " << child->ancLockCount
             << " decLockCount: " << child->decLockCount
             << " isLocked: " << child->isLocked << " uid: " << child->uid << "\n";
    }
    cout << "\n";
    for (const auto& child : root->children) {
        printTree(child);
    }
}

struct Tree {
    Node* root;
    unordered_map<string, Node*> valToNode;

    Tree(Node* r) : root(r) {}

    // pre-order traversal
    void fillValToNode(Node* node) {
        if (!node)
            return;
        valToNode[node->val] = node;
        for (const auto& child : node->children)
            fillValToNode(child);
    }

    void updateDescendants(Node* node, int count) {
        for (const auto& child : node->children) {
            child->ancLockCount += count;
            updateDescendants(child, count);
        }
    }

    bool verifyDescendants(Node* node, int id, vector<Node*>& lockedNodes) {
        if (node->isLocked) {
            if (node->uid != id)
                return false;
            lockedNodes.push_back(node);
        }
        if (node->decLockCount == 0)
            return true;

        bool result = true;
        for (const auto& child : node->children) {
            result &= verifyDescendants(child, id, lockedNodes);
            if (!result)
                return false;
        }
        return result;
    }

    bool lockNode(const string& val, int id) {
        Node* node = valToNode[val];
        if (node->isLocked || node->ancLockCount != 0 || node->decLockCount != 0)
            return false;

        Node* curr = node->parent;
        while (curr) {
            curr->decLockCount++;
            curr = curr->parent;
        }
        updateDescendants(node, 1);
        node->isLocked = true;
        node->uid = id;
        return true;
    }

    bool unlockNode(const string& val, int id) {
        Node* node = valToNode[val];
        if (!node->isLocked || (node->isLocked && node->uid != id))
            return false;

        Node* curr = node->parent;
        while (curr) {
            curr->decLockCount--;
            curr = curr->parent;
        }
        updateDescendants(node, -1);
        node->isLocked = false;
        return true;
    }
    bool upgradeNode(const string& val, int id) {
        Node* node = valToNode[val];
        if (node->isLocked || node->ancLockCount != 0 || node->decLockCount == 0)
            return false;

        vector<Node*> lockedNodes;
        if (verifyDescendants(node, id, lockedNodes)) {
            for (auto lockedNode : lockedNodes) {
                unlockNode(lockedNode->val, id);
            }
        } else {
            return false;
        }
        lockNode(val, id);
        return true;
    }
};

Node* buildTree(Node* root, int& childCount, vector<string>& values) {
    queue<Node*> q;
    q.push(root);
    // world, asia, africa, india, pak, us, uk == 7
    int start = 1;
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (start >= values.size())
            continue;

        vector<string> childrenVals;
        for (int i = start; i < start + childCount; i++)
            childrenVals.push_back(values[i]);
        node->addChildren(childrenVals, node);
        start += childCount;

        for (const auto& child : node->children)
            q.push(child);
    }

    return root;
}

int main() {
    int nodeCount, childCount, queryCount;
    cin >> nodeCount >> childCount >> queryCount;

    vector<string> values(nodeCount);
    for (int i = 0; i < nodeCount; i++)
        cin >> values[i];

    Node* rootNode = new Node(values[0], nullptr);
    // world, asia, africa, india, pak, us, uk
    rootNode = buildTree(rootNode, childCount, values);
    // printTree(rootNode);

    Tree tree(rootNode);
    tree.fillValToNode(tree.root);

    int operation, uniqueID;
    string nodeValue;
    for (int i = 0; i < queryCount; i++) {
        cin >> operation >> nodeValue >> uniqueID;
        switch (operation) {
            case 1:
                if (tree.lockNode(nodeValue, uniqueID)) {
                    cout << "true\n";
                    // printTree(rootNode);
                } else {
                    cout << "false\n";
                }
                break;
            case 2:
                if (tree.unlockNode(nodeValue, uniqueID))
                    cout << "true\n";
                else
                    cout << "false\n";
                break;
            case 3:
                if (tree.upgradeNode(nodeValue, uniqueID)) {
                    cout << "true\n";
                    // printTree(rootNode);
                } else {
                    cout << "false\n";
                }
                break;
        }
    }
    return 0;
}