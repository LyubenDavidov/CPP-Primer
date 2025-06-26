#include <iostream>
using namespace std;

int main() {
    string word;

    // this will separate the string input into individual words
    /*
     *   while (cin >> word) {
     *       cout << word << endl;
     *   }
     */

    // this will print the entire string line until newline or end-of-script
    string line;
    while (getline(cin, line)) {
        if (!line.empty()) {        // if line is not empty we get print
            cout << line << endl;
        }
    }
    return 0;
}