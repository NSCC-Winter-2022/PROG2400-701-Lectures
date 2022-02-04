#include "grade.h"

Grade::Grade(int mark, int total)
    : m_mark(mark)
    , m_total(total) {
}

bool Grade::operator!=(Grade grade) {
    return (this->m_mark != grade.m_mark) || (this->m_total != grade.m_total);
}

std::ostream& operator<<(std::ostream& output, Grade grade) {
    output << "Grade: " << grade.m_mark << "/" << grade.m_total;
    return output;
}
