#include <iostream>

using namespace std;

class Node {
public:
    int m_data {-1};
    Node* m_next {nullptr};
};

class Stack {
private:
    Node* m_top {nullptr};

public:
    Stack() = default;
    virtual ~Stack() {
    }

    void push(int num) {

        auto new_node = new Node();
        new_node->m_data = num;
        new_node->m_next = m_top;
        m_top = new_node;
    }

    int peek() {
        if (m_top != nullptr)
            return m_top->m_data;
        return -1;
    }

    void pop() {
        if (m_top != nullptr) {
            auto node = m_top;
            m_top = m_top->m_next;
            delete node;
        } else {
            cout << "There are no more nodes to remove..." << endl;
        }
    }

    friend ostream& operator<<(ostream& output, Stack& stack);
};

ostream& operator<<(ostream& output, Stack& stack) {
    auto node = stack.m_top;
    while (node != nullptr) {
        output << node->m_data << " ";
        node = node->m_next;
    }
    return output;
}

int main() {

    Stack stack;

    // test 1 - add one node to stack
    cout << "Test 1: add a single value" << endl;
    cout << "--------------------------" << endl;

    stack.push(1);

    cout << stack << endl;

    // test 2 - add more nodes to stack
    cout << "Test 2: add more nodes" << endl;
    cout << "----------------------" << endl;

    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout << stack << endl;

    // test 3 - take a look at the top of the stack
    cout << "Test 3: peek at the first value" << endl;
    cout << "-------------------------------" << endl;

    cout << stack.peek() << endl;

    // test 4 - remove a node from the top of the stack
    cout << "Test 4: pop a node off the stack" << endl;
    cout << "--------------------------------" << endl;

    stack.pop();

    cout << stack << endl;

    // test 5 - remove the remaining nodes
    cout << "Test 5: pop all nodes off the stack" << endl;
    cout << "-----------------------------------" << endl;

    while (stack.peek() != -1) {
        stack.pop();
    }

    cout << stack << endl;

    // test 6 - try to pop off empty stack
    cout << "Test 6: try and pop off empty stack" << endl;
    cout << "-----------------------------------" << endl;

    stack.pop();

    cout << stack << endl;

    return 0;
}