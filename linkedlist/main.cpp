#include <iostream>

using namespace std;

class LinkedListNode {
public:
    int m_data { -1 };                      // the data to be stored
    LinkedListNode* m_next { nullptr };     // a pointer to the next node in the chain
};

class LinkedList {
private:
    LinkedListNode* m_start { nullptr };

public:
    LinkedList() {}
    virtual ~LinkedList() {
        LinkedListNode *node = m_start;

        while (node != nullptr) {
            LinkedListNode* temp = node;
            node = node->m_next;
            delete temp;
        }
    }

    void add(int data) {

        LinkedListNode* new_node = new LinkedListNode();
        new_node->m_data = data;

        // are there nodes in the list?
        if (m_start == nullptr) {
            // add the first node
            m_start = new_node;
        } else {
            // add additional nodes
            LinkedListNode* node = m_start;
            LinkedListNode* prev = nullptr;

            // go through each node until you hit null
            while (node != nullptr) {
                prev = node;
                node = node->m_next;
            }

            // attach node to end of chain
            if (prev != nullptr) {
                prev->m_next = new_node;
            }
        }
    }

    void remove(int data) {

        LinkedListNode* node = m_start;
        LinkedListNode* prev = nullptr;

        // find the node to delete
        while (node != nullptr) {
            // find a node with the right data
            if (node->m_data == data) {
                break;
            }
            prev = node;
            node = node->m_next;
        }

        // did I find the node?
        if (node != nullptr) {
            // are we deleting the first node? or another node?
            if (prev == nullptr) {
                // first node
                m_start = node->m_next;
            } else {
                // another node
                prev->m_next = node->m_next;
            }

            delete node;
        } else {
            cout << "There is no such animal...." << endl;
        }

    }

    friend ostream& operator<<(ostream& output, LinkedList& list);
};

ostream& operator<<(ostream& output, LinkedList& list) {

    LinkedListNode* node = list.m_start;

    while (node != nullptr) {
        output << node->m_data << " ";
        node = node->m_next;
    }

    return output;
}

int main() {

    LinkedList list;

    // test 1 - add a node to the list
    list.add(1);

    cout << "Test 1" << endl;
    cout << "------" << endl;

    cout << list << endl;

    // test 2 - add another node to the list
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    cout << "Test 2" << endl;
    cout << "------" << endl;

    cout << list << endl;

    // test 3 - delete a node in the middle of the chain
    list.remove(3); // remove the node with the data of 3

    cout << "Test 3" << endl;
    cout << "------" << endl;

    cout << list << endl;

    // test 4 - delete the last node in the chain
    list.remove(5); // remove the node with the data of 5

    cout << "Test 4" << endl;
    cout << "------" << endl;

    cout << list << endl;

    // test 5 - delete the first node in the chain
    list.remove(1); // remove the node with the data of 1

    cout << "Test 5" << endl;
    cout << "------" << endl;

    cout << list << endl;

    return 0;
}