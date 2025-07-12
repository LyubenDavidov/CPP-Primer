#include <iostream>
#include <vector>
using namespace std;

int main(){
    // vowel counter
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, uCnt = 0, oCnt = 0;
    char ch;

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
        }
    }

    cout << "Number of vowel a: \t" << aCnt << "\n"
         << "Number of vowel e: \t" << eCnt << "\n"
         << "Number of vowel i: \t" << iCnt << "\n"
         << "Number of vowel o: \t" << oCnt << "\n"
         << "Number of vowel u: \t" << uCnt << endl;
    return 0;
}