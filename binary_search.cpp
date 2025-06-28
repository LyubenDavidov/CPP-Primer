#include <iostream>
#include <vector>
using namespace std;

int main(){
    // initialize ordered string vector of letters
    vector<string> text {"is", "my", "string", "this", "using", "vector", "word", "zener"};

    string sought = "vector";

    // begin and end will denote the range we are searching
    auto beg = text.begin(), end = text.end();  // original begin and end points
    auto mid = text.begin() + (end - beg)/2;    // original midpoint

    while (mid != end && *mid != sought){
        if (sought < *mid){
            end = mid;
        }
        else{
            beg = mid + 1;
        }
        mid = beg + (end - beg)/2;
    }

    // important:: cout can't print iterator_type that is mid alone but it
    //             can print difference_type that is mid - text.begin()
    cout << "Index is: " << mid - text.begin() << endl;
    return 0;
}