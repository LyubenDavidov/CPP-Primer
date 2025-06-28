#include <iostream>
#include <vector>
using std::vector;

int main() {

    // define a vector
    vector<int> ivec0;   // ivec holds objects of type int

    // list initialization of a vector
    vector<int> ivec1 {3, 6, 8, 9};

    // print ivec1
    for (int i; i<=3; i++){
        std::cout << ivec1[i] << std::endl;
    }

    // initialize a vector by copying 
    vector<int> ivec_copy (ivec1);

    // print ivec_copy
    for (int i; i<=3; i++){
        std::cout << ivec_copy[i] << std::endl;
    }

    // initialize a vector with 10 elements that are 2
    vector<int> ivec2 (10, 2);

    // print ivec2
    for (decltype(ivec2.size()) i = 0; i<ivec2.size(); i++){
        std::cout << ivec2[i] << std::endl;
    }

    // alternative way to print ivec2
    for (auto val : ivec2){
        std::cout << val << std::endl;
    }
    
    // fill empty vector with elements
    vector<int> ivec3;
    for (int i = 0; i != 100; i++){
        ivec3.push_back(i);             // append sequential integers to ivec3
    }

    // short script to order grades in a distribution
    vector<unsigned> scores (11,0); // 11 buckets
    unsigned grade;
    while (std::cin >> grade){
        if (grade<=100){        // only valid grades accepted
            ++scores[grade/10]; // increment the counter for the current cluster 
        }
    }

    // print grade distribution
    for (decltype(scores.size()) i = 0; i<scores.size(); i++){
        std::cout << scores[i] << " ";
    }
    std::cout << " " << std::endl;

    return 0;
}