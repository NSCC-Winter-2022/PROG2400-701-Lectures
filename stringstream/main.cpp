#include <iostream>
#include <sstream>
#include <cstring>
#include <istream>

using namespace std;

int main() {

    char input[256];
    char command[256];
    int start, end;

    cout << "Enter a command: ";
    cin.getline(input, 256);

    stringstream ss;
    ss << input;

    //ss.getline(command, 256, ',');
    ss >> command;

    // check for possible command
    // commands are one character, text is multiple characters
    if (strlen(command) > 1) {
        // more than one character means that it is text
        cout << "You entered some text." << endl;
    } else {
        // one character means that it *could* be a command
        cout << "You might have entered a command." << endl;

        // check to see if it is a command
        if (command[0] == 'I') {
            // you entered an 'insert' command
            ss >> start;
            if (!ss) {
                // a command wasn't followed by a number!
                cout << "error!" << endl;
            } else {
                ss >> end;

                cout << "You typed a '" << command << "' command." << endl;
                cout << "The range is from lines " << start << " to " << end << endl;
            }
        } else {
            // you entered an unsupported command
            cout << "You entered a single letter." << endl;
        }
    }

    return 0;
}