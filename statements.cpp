#include <iostream>
#include <vector>
using namespace std;

int main(){
    // vowel counter
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, uCnt = 0, oCnt = 0, otherCnt = 0;
    char ch;
    /*
    while (cin >> ch){
        switch (ch){
            case 'a':
                ++aCnt;
                break;
            
            case 'e':
                ++eCnt;
                break;

            case 'i':
                ++iCnt;
                break;

            case 'u':
                ++uCnt;
                break;

            case 'o':
                ++oCnt;
                break;

            default:
                ++otherCnt;
                break;
        }
    }

    cout << "Number of vowel a: \t" << aCnt << "\n"
         << "Number of vowel e: \t" << eCnt << "\n"
         << "Number of vowel i: \t" << iCnt << "\n"
         << "Number of vowel o: \t" << oCnt << "\n"
         << "Number of vowel u: \t" << uCnt << "\n"
         << "Number of other characters: \t" << otherCnt << endl;

    */

    // small change
    vector<int> v;
    int i;
    while (cin >> i){
        v.push_back(i);
    }

    auto beg = v.begin();
    while (beg != v.end() && *beg >= 0){
        ++beg;
    }

    if (beg == v.end())
        cout << "All elements in v are greater than or equal to 0" << endl;
    else
        cout << "You have negative elements" << endl;
    return 0;
}