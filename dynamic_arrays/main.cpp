#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

ostream &operator<<(ostream &output, const vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ' ';
    }
    return output;
}

int main() {

    int static_nums[] = {1, 2, 3, 4, 5};

    // created a new dynamic array
    vector<int> nums {1, 2, 3, 4, 5};
    //nums.reserve(100);
    cout << setw(11) << "initial) ";
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    // add to the vector
    nums.push_back(6);
    cout << setw(11) << "push_back) ";
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    // remove from the vector
    nums.resize(4);
    cout << setw(11) << "resize) ";
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    // add more to the vector
    for (int i = 0; i < 10; ++i) {
        nums.push_back(7+i);
    }
    cout << setw(11) << "push_back) ";
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    // shrink the memory
    nums.shrink_to_fit();
    cout << setw(11) << "shrink) ";
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    // clear the elements out
    nums.clear();
    cout << setw(11) << "clear) ";
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    // shrink the memory
    nums.shrink_to_fit();
    cout << setw(11) << "shrink) ";
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    return 0;
}