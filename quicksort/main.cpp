#include <iomanip>
#include <iostream>

using namespace std;

void dump_array(int* array, int len) {
    for (int i = 0; i < len; i++) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

int split(int* array, int first, int last) {

    // pick a pivot point
    int pivot = array[first];

    // keep track of numbers less than or greater than the pivot point
    int left = first;
    int right = last;

    while (left < right) {

        // find first number less than the pivot point
        while (pivot > array[right])
            right--;

        // find first number greater than the pivot point
        while (pivot <= array[left])
            left++;

        // swap them
        if (left < right) {
            swap(array[left], array[right]);
        }
    }

    // move pivot to correct spot
    array[first] = array[right];
    array[right] = pivot;

    return right;
}

void quick_sort(int* array, int first, int last) {

    // how do we end the recursion?
    // if the array has only one element, first == last
    // if the array has no elements, first > last

    if (first < last) {
        // split into sublists
        // "pos" is the index of the pivot point
        int pos = split(array, first, last);

        // quicksort the left sublist
        quick_sort(array, first, pos - 1);

        // quicksort the right sublist
        quick_sort(array, pos + 1, last);
    }
}

int main() {

    int nums[] = {3, 6, 8, 10, 5, 9, 4, 1, 2, 7};
    int len = sizeof(nums) / sizeof(int);

    cout << "Before Sorting..." << endl;
    dump_array(nums, len);

    quick_sort(nums, 0, len - 1);

    cout << "After Sorting..." << endl;
    dump_array(nums, len);

    return 0;
}