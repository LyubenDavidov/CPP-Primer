#include "factorial.hpp"

int factorial(int val){
    int ret = 1;
    while (val > 1){
        ret *= val--;
    }
    return ret;
}