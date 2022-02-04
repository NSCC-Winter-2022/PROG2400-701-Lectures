#include "stack.h"
#include <iostream>

using namespace std;

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