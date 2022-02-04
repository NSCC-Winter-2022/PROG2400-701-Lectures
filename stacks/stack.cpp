#include "stack.h"
#include <iostream>

Stack::~Stack() {
}

void Stack::push(int num) {

    auto new_node = new Node();
    new_node->m_data = num;
    new_node->m_next = m_top;
    m_top = new_node;
}

int Stack::peek() {
    if (m_top != nullptr)
        return m_top->m_data;
    return -1;
}

void Stack::pop() {
    if (m_top != nullptr) {
        auto node = m_top;
        m_top = m_top->m_next;
        delete node;
    } else {
        std::cout << "There are no more nodes to remove..." << std::endl;
    }
}

std::ostream& operator<<(std::ostream& output, Stack& stack) {
    auto node = stack.m_top;
    while (node != nullptr) {
        output << node->m_data << " ";
        node = node->m_next;
    }
    return output;
}
