#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("example.txt");

    if(!file.is_open()){
        cout << "File not opened\n";
        return 1;
    }

    string line;
    while(getline(file, line)){
        cout << line << endl;
    }

    file.close();
    return 0;
}
