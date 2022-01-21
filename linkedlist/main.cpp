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

    void insert(int data, int position) {

        LinkedListNode* new_node = new LinkedListNode();
        // check to see if memory was allocated
        new_node->m_data = data;

        // find the node to insert before
        int curr_pos = 1;
        LinkedListNode* node = m_start;
        LinkedListNode* prev = nullptr;

        while (node != nullptr) {

            if (curr_pos++ == position) {
                break;
            }

            prev = node;
            node = node->m_next;
        }

        if (node != nullptr) {
            if (prev == nullptr) {
                // inserting before the first node
                new_node->m_next = m_start;
                m_start = new_node;
            } else {
                // inserting in the middle
                new_node->m_next = prev->m_next;
                prev->m_next = new_node;
            }
        } else {
            cout << "Position doesn't exist." << endl;
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

    // test 1 - add a node to the list
    cout << "Test 1" << endl;
    cout << "------" << endl;

    list.add(1);

    cout << list << endl;

    // test 2 - add another node to the list
    cout << "Test 2" << endl;
    cout << "------" << endl;

    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    cout << list << endl;

    // test 3 - delete a node in the middle of the chain
    cout << "Test 3" << endl;
    cout << "------" << endl;

    list.remove(3); // remove the node with the data of 3

    cout << list << endl;

    // test 4 - delete the last node in the chain
    cout << "Test 4" << endl;
    cout << "------" << endl;

    list.remove(5); // remove the node with the data of 5

    cout << list << endl;

    // test 5 - delete the first node in the chain
    cout << "Test 5" << endl;
    cout << "------" << endl;

    list.remove(1); // remove the node with the data of 1

    cout << list << endl;

    // test 6 - insert a node before a node in the chain
    cout << "Test 6" << endl;
    cout << "------" << endl;

    list.insert(6, 2); // insert value 6 before the second node

    cout << list << endl;

    // test 7 - insert a node before an invalid node in the chain
    cout << "Test 7" << endl;
    cout << "------" << endl;

    list.insert(10, 4); // insert value 10 before the fourth node

    cout << list << endl;

    // test 8 - insert a node before the first node in the chain
    cout << "Test 8" << endl;
    cout << "------" << endl;

    list.insert(7, 1); // insert value 7 before the first node

    cout << list << endl;

    return 0;
}