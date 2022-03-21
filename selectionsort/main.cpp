#include <iomanip>
#include <iostream>

using namespace std;

void dump_array(int* array, int len) {
    for (int i = 0; i < len; i++) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

void selection_sort(int* array, int len) {

    // find the smallest numbers and put them in their spot (ascending order)
    // find the largest numbers (descending order)
    for (int i = 0; i < len - 1; i++) {

        // find the smallest (or largest) number
        int lowest = i;
        for (int j = i; j < len; j++) {
            if (array[j] < array[lowest]) {
                lowest = j;
            }
        }

        // if a swap is needed
        if (array[lowest] < array[i]) {
            // swap them
            int temp = array[lowest];
            array[lowest] = array[i];
            array[i] = temp;
        }
    }
}

int main() {

    int nums[] = {3, 6, 8, 10, 5, 9, 4, 1, 2, 7};
    int len = sizeof(nums) / sizeof(int);

    cout << "Before Sorting..." << endl;
    dump_array(nums, len);

    selection_sort(nums, len);

    cout << "After Sorting..." << endl;
    dump_array(nums, len);

    return 0;
}