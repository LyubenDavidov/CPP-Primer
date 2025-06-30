#include <iostream>
#include <vector>
using namespace std;

int main(){
    // count the number of grades in clusters
    unsigned scores[11] = {};
    unsigned grade;

    while (cin >> grade){
        if (grade <= 100){
            ++scores[grade/10];
        }
        else{
            cout << "Grade must be between 0 and 100. \nTerminating..." << endl;
            return -1;
        }
    }

    // print grade distribution
    for (unsigned i = 0; i<11; i++){
        std::cout << scores[i] << " ";
    }
    std::cout << " " << std::endl;
    return 0;
}
