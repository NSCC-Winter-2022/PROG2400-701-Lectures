#ifndef _GRADE_H
#define _GRADE_H

#include <iostream>

class Grade {
public:
    int m_mark;
    int m_total;

    Grade(int, int);

    bool operator!=(Grade grade);
};

std::ostream& operator<<(std::ostream& output, Grade grade);

#endif