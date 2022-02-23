#include <fstream>
#include <iostream>

using namespace std;

class Data {
public:
    string m_data;
};

istream&
operator>>(istream& input, Data& data) {

    getline(input, data.m_data);

    return input;
}

int main() {

    ifstream file("sample.txt");

    Data data;
    file >> data;

    cout << data.m_data << endl;

    cin >> data;
    cout << data.m_data << endl;

    Maze maze;
    file >> maze;
    maze.read(??)
    maze.get_data_from_file(....)
    
    file << maze;

    return 0;
}