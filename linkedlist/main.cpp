#include <iostream>
#include "linkedlist.h"

using namespace std;

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