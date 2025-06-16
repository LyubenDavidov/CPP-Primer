// SCRIPT TO SHOW LITERALS AND INITIALIZATION
#include <iostream>

int main() {

    // print Hi MOM! with literals in decimal/octal/hexadecimal
    std::cout << "Hi \x4dO\115!\n" << std::endl;

    // specifying type of a literal
    std::cout << L'a' << std::endl;     // wide character literal, type is wchar_t
    std::cout << u8"hi!" << std::endl;  // utf-8 string literal (utf-8 encodes a Unicode character in 8 bits)
    std::cout << 42ULL << std::endl;    // unsigned integer literal, type is unsigned long long
    std::cout << 1E-3F << std::endl;    // single-precision floating-point literal, type is float
    std::cout << 3.14159L << std::endl; // extended-precision floating-point literal, type is long double

    // example of initialization
    long double ld = 3.1415926536;
    int a{ld}, b = {ld};    // error: narrowing conversion required
    int c(ld), d = ld;      // ok: but value will be truncated

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    return 0;
}