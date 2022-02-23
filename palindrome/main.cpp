#include <cstring>
#include <iostream>

using namespace std;

bool is_palindrome(char* str, int len) {
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

bool is_palindrome_recursive(char* str, int len) {

    if (len <= 1)
        return true;

    // racecar = check 'r's and pass the rest on
    if (str[0] != str[len - 1]) {
        return false;
    }

    char* substr = new char[len - 1];
    strncpy(substr, &str[1], len - 2);
    substr[len - 2] = '\0';

    bool retval = is_palindrome_recursive(substr, len - 2);

    delete[] substr;

    return retval;
}

int main() {

    char buffer[256];

    cout << "Enter a word: ";
    cin.getline(buffer, 256);

    int len = strlen(buffer);

    cout << buffer << " IS";
    if (!is_palindrome(buffer, len)) {
        cout << " NOT";
    }
    cout << " a palindrome!" << endl;

    cout << buffer << " IS";
    if (!is_palindrome_recursive(buffer, len)) {
        cout << " NOT";
    }
    cout << " a palindrome!" << endl;

    return 0;
}