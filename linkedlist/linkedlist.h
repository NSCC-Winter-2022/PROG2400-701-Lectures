#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

class LinkedList {

    class LinkedListNode {
    public:
        int m_data { -1 };                      // the data to be stored
        LinkedListNode* m_next { nullptr };     // a pointer to the next node in the chain
    };

private:
    LinkedListNode* m_start { nullptr };

public:
    LinkedList();
    virtual ~LinkedList();

    void add(int data);
    void insert(int data, int position);
    void remove(int data);

    friend std::ostream& operator<<(std::ostream& output, LinkedList& list);
};

std::ostream& operator<<(std::ostream& output, LinkedList& list);

#endif 