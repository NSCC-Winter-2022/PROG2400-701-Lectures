#include <iostream>
#include <regex>

using namespace std;

int main() {

    auto const r = std::regex("[^a-zA-Z ]");

    auto s = "t3st str1ng";

    cout << std::regex_replace(s, r, "");

    return 0;
}