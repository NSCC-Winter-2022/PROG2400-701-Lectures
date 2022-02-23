#include <iostream>

using namespace std;

int cnt = 0;

void recursive_function() {
    cout << "Hello World" << endl;

    cnt++;

    if (cnt < 10000000) {
        // recursion
        recursive_function();
    }
}

int main() {

    recursive_function();

    return 0;
}