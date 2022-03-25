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

    void remove(int num) {

        NodePtr node = m_root;
        NodePtr parent = nullptr;

        // find the node to delete
        while (node != nullptr) {
            if (num < node->m_data) {
                parent = node;
                node = node->m_left;
            } else if (num > node->m_data) {
                parent = node;
                node = node->m_right;
            } else {
                // found the node!
                break;
            }
        }

        // did we find the node? exit if didn't
        if (node == nullptr)
            return;

        // if a node has two children,
        // use the right-most node in the left subtree as successor
        if (node->m_left != nullptr && node->m_right != nullptr) {
            // start at left subtree
            NodePtr successor = node->m_left;

            // keep going right as far as possible
            parent = node;
            while (successor->m_right != nullptr) {
                parent = successor;
                successor = successor->m_right;
            }

            // swap the data between node and successor
            node->m_data = successor->m_data;
            node = successor;
        }

        // does the node have any children?
        NodePtr subtree = node->m_left;
        if (subtree == nullptr) {
            subtree = node->m_right;
        }

        // connect children to new parent
        if (parent == nullptr) {
            // we are at the root!
            m_root = subtree;
        } else if (parent->m_left == node) {
            parent->m_left = subtree;
        } else if (parent->m_right == node) {
            parent->m_right = subtree;
        }

        // finally delete the node
        delete node;
    }

    void save_array(int* array) {
        save_array(array, m_root);
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

    void save_array(int* array, NodePtr node) {

        // the array index to store the value
        static int i = 0;

        if (node != nullptr) {
            save_array(array, node->m_right);
            array[i++] = node->m_data;
            save_array(array, node->m_left);
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

void bst_sort(int* array, int len) {

    BST bst;

    for (int i = 0; i < len; i++) {
        bst.insert(array[i]);
    }

    bst.save_array(array);
}

void dump_array(int* array, int len) {
    for (int i = 0; i < len; i++) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

int main() {

    int nums[] = {3, 6, 8, 10, 5, 9, 4, 1, 2, 7};
    int len = sizeof(nums) / sizeof(int);

    cout << "Before Sorting..." << endl;
    dump_array(nums, len);

    bst_sort(nums, len);

    cout << "After Sorting..." << endl;
    dump_array(nums, len);

    return 0;
}