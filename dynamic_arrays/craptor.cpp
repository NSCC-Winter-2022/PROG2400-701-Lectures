#include <iostream>
#include <cstring>

using namespace std;

class Craptor {

private:
    int *m_nums;
    int m_capacity;
    int m_size;

public:
    Craptor() : m_nums(nullptr), m_capacity(0), m_size(0) {}
    virtual ~Craptor() {
        delete[] m_nums;
    }

    void add(int num) {

        if (m_size == m_capacity) {

            int *temp = m_nums;

            // allocate a block of memory
            m_nums = new int[m_capacity + 5];
            m_capacity += 5;

            int i;
            for(i = 0; i < m_size; i++) {
                m_nums[i] = temp[i];
            }

            delete[] temp;
        }

        m_nums[++m_size] = num;
    }

    void resize(int size) {
        int *temp = m_nums;
        m_nums = new int[size];

        int i;
        for(i = 0; i < size; i++) {
            m_nums[i] = temp[i];
        }
        m_size = size;

        delete[] temp;
    }

    friend ostream& operator<<(ostream& output, Craptor& c);
};

ostream& operator<<(ostream& output, Craptor& c) {

    cout << "capacity: " << c.m_capacity << ") ";
    for (int i = 0; i < c.m_size; ++i) {
        cout << c.m_nums[i] << ' ';
    }
    return output;
}

int main() {

    // create a new Craptor
    Craptor craptor;
    craptor.add(1);
    craptor.add(2);
    craptor.add(3);
    craptor.add(4);
    craptor.add(5);

    cout << craptor << endl;

    // resize the Craptor
    craptor.resize(3);

    cout << craptor << endl;

    return 0;
}
