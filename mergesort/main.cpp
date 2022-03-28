#include <iomanip>
#include <iostream>

using namespace std;

void dump_array(int* array, int len) {
    for (int i = 0; i < len; i++) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

void split(int* inarray, int len, int* outarray1, int* outsize1, int* outarray2, int* outsize2) {

    int subfiles = 0;
    int in = 0;
    *outsize1 = 0;
    *outsize2 = 0;

    // read first record
    int curr;
    int next = inarray[in++];

    while (in <= len) {

        // write subfile to correct temporary file
        do {
            curr = next;

            // read next record
            if (in < len) {
                next = inarray[in];
            }
            in++;

            // write record to correct temporary file
            if (subfiles % 2 == 0) {
                outarray1[(*outsize1)++] = curr;
            } else {
                outarray2[(*outsize2)++] = curr;
            }

        } while ((in <= len) && (curr >= next));

        subfiles++;
    }
}

int merge(int* outarray, int* outsize, int* inarray1, int insize1, int* inarray2, int insize2) {

    // needed for the array version to keep track of position in each array
    int in1 = 0;
    int in2 = 0;
    *outsize = 0;

    // the total number of subfiles in the resulting merged file
    int subfiles = 0;

    int prev1;
    int prev2;

    // read first records from each temporary array
    int curr1;
    int curr2;

    curr1 = inarray1[in1++];
    curr2 = inarray2[in2++];

    // loop while both temporary arrays have records
    while (in1 <= insize1 && in2 <= insize2) {

        bool end_of_sub1 = false;
        bool end_of_sub2 = false;

        // keep reading from both files while their records are still in the same subfile
        while (!end_of_sub1 && !end_of_sub2) {
            // compare records

            // write out the lower record (ascending order)
            if (curr1 >= curr2) {

                // write out the record
                outarray[(*outsize)++] = curr1;

                // read in another record
                prev1 = curr1;
                if (in1 < insize1) {
                    curr1 = inarray1[in1];
                }
                in1++;

                // am I still in the same sublist?
                if ((in1 > insize1) || (prev1 < curr1)) {
                    end_of_sub1 = true;
                }
            }

            if (curr2 >= curr1) {
                // write out the record
                outarray[(*outsize)++] = curr2;

                // read in another record
                prev2 = curr2;
                if (in2 < insize2) {
                    curr2 = inarray2[in2];
                }
                in2++;

                // am I still in the same sublist?
                if ((in2 > insize2) || (prev2 < curr2)) {
                    end_of_sub2 = true;
                }
            }
        }

        // if not in the same sublist
        // write out remaining records from the same sublist from the other temp array

        // do I need to write out the records from the first file?
        while (!end_of_sub1) {
            // write out the record
            outarray[(*outsize)++] = curr1;

            // read in another record
            prev1 = curr1;
            if (in1 < insize1) {
                curr1 = inarray1[in1];
            }
            in1++;

            // am I still in the same sublist?
            if ((in1 > insize1) || (prev1 < curr1)) {
                end_of_sub1 = true;
            }
        }

        // or the second file??
        while (!end_of_sub2) {
            // write out the record
            outarray[(*outsize)++] = curr2;

            // read in another record
            prev2 = curr2;
            if (in2 < insize2) {
                curr2 = inarray2[in2];
            }
            in2++;

            // am I still in the same sublist?
            if ((in2 > insize2) || (prev2 < curr2)) {
                end_of_sub2 = true;
            }
        }

        subfiles++;
    }

    // write out remaining records in whichever array still has records

    // dump the remaining records from file1
    while (in1 <= insize1) {
        // write out the record
        outarray[(*outsize)++] = curr1;

        // read in another record
        prev1 = curr1;
        if (in1 < insize1) {
            curr1 = inarray1[in1];
        }
        in1++;

        // am I still in the same sublist?
        if ((in1 > insize1) || (prev1 < curr1)) {
            subfiles++;
        }
    }

    // or the second file??

    // dump the remaining records from file2
    while (in2 <= insize2) {
        // write out the record
        outarray[(*outsize)++] = curr2;

        // read in another record
        prev2 = curr2;
        if (in2 < insize2) {
            curr2 = inarray2[in2];
        }
        in2++;

        // am I still in the same sublist?
        if ((in2 > insize2) || (prev2 < curr2)) {
            subfiles++;
        }
    }

    return subfiles;
}

void merge_sort(int* array, int len) {

    int subfiles = 0;
    int* temp1 = new int[len];
    int* temp2 = new int[len];
    int tempsize1;
    int tempsize2;

    // loop until one ordered list remains
    do {

        // split original array into two temporary arrays
        split(array, len, temp1, &tempsize1, temp2, &tempsize2);

        // merge temporary arrays into original array
        subfiles = merge(array, &len, temp1, tempsize1, temp2, tempsize2);

    } while (subfiles != 1);

    delete[] temp1;
    delete[] temp2;
}

int main() {

    int nums[] = {3, 6, 8, 10, 5, 9, 4, 1, 2, 7};
    int len = sizeof(nums) / sizeof(int);

    cout << "Before Sorting..." << endl;
    dump_array(nums, len);

    merge_sort(nums, len);

    cout << "After Sorting..." << endl;
    dump_array(nums, len);

    return 0;
}