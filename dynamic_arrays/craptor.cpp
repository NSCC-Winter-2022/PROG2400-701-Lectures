#include <iostream>

using namespace std;

int len = 0;

ostream& operator<<(ostream& output, int nums[]) {
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << ' ';
    }
    return output;
}

int main() {

    // starting point: static array
    int nums[] = {1, 2, 3, 4, 5};
    len = sizeof(nums) / sizeof(nums[0]);

    cout << nums << endl;

    // add an element to the array
    int nums2_len = len + 1;
    int nums2[nums2_len];

    // copy from old array into the new array
    int i = 0;
    for (; i < len; ++i) {
        nums2[i] = nums[i];
    }

    // add new element to new array
    nums2[i] = 6;

    // set array len to new array size
    len = nums2_len;

    cout << nums2 << endl;

    return 0;
}
