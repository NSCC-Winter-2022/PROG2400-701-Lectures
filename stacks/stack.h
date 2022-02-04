#ifndef _STACK_H
#define _STACK_H

#include <iostream>

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
    virtual ~Stack();

    void push(int num);
    int peek();
    void pop();

    friend std::ostream& operator<<(std::ostream& output, Stack& stack);
};

std::ostream& operator<<(std::ostream& output, Stack& stack);

#endif