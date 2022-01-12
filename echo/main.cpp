#include <iostream>
#include <cstring>

using namespace std;
// using std::cout, std::endl;

void to_lower(char *text, size_t len) {
    for (int i = 0; i < len; ++i) {
        text[i] = (char)tolower(text[i]);
    }
}

int main() {

    const int BUFFER_SIZE = 256;
    const int STREAM_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    char input[BUFFER_SIZE];
    bool done = false;

    while (!done) {

        cout << "Enter some text: ";
        cin.getline(input, BUFFER_SIZE);

        if (!cin) {
            cin.clear();
            cin.ignore(STREAM_SIZE, '\n');
        }

        memcpy(buffer, input, BUFFER_SIZE);
        to_lower(buffer, strlen(buffer));

        if (!strncmp(buffer, "end", BUFFER_SIZE - 1)) {
            done = true;
        } else {
            cout << "You typed: " << buffer << endl;
        }
    }

    return 0;
}