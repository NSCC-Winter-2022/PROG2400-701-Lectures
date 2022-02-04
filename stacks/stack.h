#ifndef _STACK_H
#define _STACK_H

#include "grade.h"
#include <iostream>

class Node {
public:
    Grade m_data {-1, -1};
    Node* m_next {nullptr};
};

class Stack {
private:
    Node* m_top {nullptr};

public:
    Stack() = default;
    virtual ~Stack();

    void push(Grade num);
    Grade peek();
    void pop();

    friend std::ostream& operator<<(std::ostream& output, Stack& stack);
};

std::ostream& operator<<(std::ostream& output, Stack& stack);

#endif