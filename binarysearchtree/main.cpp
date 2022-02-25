#include <iomanip>
#include <iostream>

using namespace std;

class Node;

typedef Node* NodePtr;

class Node {
public:
    int m_data {-1};
    NodePtr m_left {nullptr};
    NodePtr m_right {nullptr};
};

class BST {
private:
    NodePtr m_root {nullptr};

public:
    BST() = default;
    virtual ~BST() = default;

    // entry point
    void insert(int num) {
        insert(num, m_root);
    }

protected:
    void insert(int num, NodePtr& node) {
        if (node == nullptr) {
            node = new Node();
            node->m_data = num;
        } else if (num < node->m_data) {
            // go left!
            insert(num, node->m_left);
        } else if (num > node->m_data) {
            // to the right with you!
            insert(num, node->m_right);
        } else {
            cout << "Node value " << node->m_data << " already exists." << endl;
        }
    }

    void print_tree(ostream& output, NodePtr& node, int indent) {
        if (node != nullptr) {
            print_tree(output, node->m_right, indent + 8);
            output << setw(indent) << node->m_data << endl;
            print_tree(output, node->m_left, indent + 8);
        }
    }

    friend ostream& operator<<(ostream& output, BST& bst);
};

ostream& operator<<(ostream& output, BST& bst) {
    bst.print_tree(output, bst.m_root, 0);
    return output;
}

int main() {

    BST bst;

    // test 1 - add some nodes
    cout << "Test 1 - adding nodes" << endl;
    cout << "---------------------" << endl;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    cout << bst << endl;

    return 0;
}