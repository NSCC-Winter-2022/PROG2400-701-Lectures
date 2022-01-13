#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    for (int i = 0; i < argc; ++i) {
        cout << (i+1) << ") " << argv[i] << endl;
    }

    // check if a filename was added as an argument
    if (argc > 1) {
        cout << "Filename: " << argv[1] << endl;
    } else {
        cout << "format: commandline.exe <filename.txt>" << endl;
    }

    return 0;
}