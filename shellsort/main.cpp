#include <iomanip>
#include <iostream>

using namespace std;

void dump_array(int* array, int len) {
    for (int i = 0; i < len; i++) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

void shell_sort(int* array, int len) {

    // determine number of subarrays
    for (int gap = len / 2; gap > 0; gap /= 2) {

        // move starting of sub array
        for (int start = 0; start < gap; start++) {

            // insertion sort
            for (int i = start + gap; i < len; i += gap) {
                int temp = array[i];

                // shuffle the values greater than the current value ahead
                int j;
                for (j = i; j >= gap && temp < array[j - gap]; j -= gap) {
                    array[j] = array[j - gap];
                }

                // insert the value in the correct spot
                array[j] = temp;
            }
        }
    }
}

int main() {

    int nums[] = {3, 6, 8, 10, 5, 9, 4, 1, 2, 7};
    int len = sizeof(nums) / sizeof(int);

    cout << "Before Sorting..." << endl;
    dump_array(nums, len);

    shell_sort(nums, len);

    cout << "After Sorting..." << endl;
    dump_array(nums, len);

    return 0;
}