#include "factorial.hpp"
#include <string>

int factorial(int val){
    int ret = 1;
    while (val > 1){
        ret *= val--;
    }
    return ret;
}

std::string::size_type find_char(const std::string &s, char c, std::string::size_type &occurs){
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i){
        if (s[i] == c){
            if (ret == s.size()){
                ret = i;
            }
            ++occurs;
        }
    }
    return ret;
}