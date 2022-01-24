#include <iostream>
#include "linkedlist.h"

LinkedList::LinkedList() {}
LinkedList::~LinkedList()
{
    LinkedListNode *node = m_start;

    while (node != nullptr)
    {
        LinkedListNode *temp = node;
        node = node->m_next;
        delete temp;
    }
}

void LinkedList::add(int data)
{

    LinkedListNode *new_node = new LinkedListNode();
    new_node->m_data = data;

    // are there nodes in the list?
    if (m_start == nullptr)
    {
        // add the first node
        m_start = new_node;
    }
    else
    {
        // add additional nodes
        LinkedListNode *node = m_start;
        LinkedListNode *prev = nullptr;

        // go through each node until you hit null
        while (node != nullptr)
        {
            prev = node;
            node = node->m_next;
        }

        // attach node to end of chain
        if (prev != nullptr)
        {
            prev->m_next = new_node;
        }
    }
}

void LinkedList::insert(int data, int position)
{

    LinkedListNode *new_node = new LinkedListNode();
    // check to see if memory was allocated
    new_node->m_data = data;

    // find the node to insert before
    int curr_pos = 1;
    LinkedListNode *node = m_start;
    LinkedListNode *prev = nullptr;

    while (node != nullptr)
    {

        if (curr_pos++ == position)
        {
            break;
        }

        prev = node;
        node = node->m_next;
    }

    if (node != nullptr)
    {
        if (prev == nullptr)
        {
            // inserting before the first node
            new_node->m_next = m_start;
            m_start = new_node;
        }
        else
        {
            // inserting in the middle
            new_node->m_next = prev->m_next;
            prev->m_next = new_node;
        }
    }
    else
    {
        std::cout << "Position doesn't exist." << std::endl;
    }
}

void LinkedList::remove(int data)
{

    LinkedListNode *node = m_start;
    LinkedListNode *prev = nullptr;

    // find the node to delete
    while (node != nullptr)
    {
        // find a node with the right data
        if (node->m_data == data)
        {
            break;
        }
        prev = node;
        node = node->m_next;
    }

    // did I find the node?
    if (node != nullptr)
    {
        // are we deleting the first node? or another node?
        if (prev == nullptr)
        {
            // first node
            m_start = node->m_next;
        }
        else
        {
            // another node
            prev->m_next = node->m_next;
        }

        delete node;
    }
    else
    {
        std::cout << "There is no such animal...." << std::endl;
    }
}

std::ostream &operator<<(std::ostream &output, LinkedList &list)
{
    LinkedList::LinkedListNode *node = list.m_start;

    while (node != nullptr)
    {
        output << node->m_data << " ";
        node = node->m_next;
    }

    return output;
}
