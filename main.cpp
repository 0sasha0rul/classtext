#include <iostream>

#include "text.hpp"

int main(){
    std::cout << "starting to test ARylova::Text by ARylova!" << std::endl;

    ARylova::Text a = "123";
    ARylova::Text b = "123";
    ARylova::Text c = "Hello";
    ARylova::Text d = "World";
    ARylova::Text e = "World";

    a = e;
    std::cout << a << std::endl;

    if (d == e) {
        std::cout << "Equals" << std::endl;
    }

    if (a != c) {
        std::cout << "Not egual"<< std::endl;
    }

    std::cout << c + d << std::endl;

    std::cout << a.at(2) << std::endl;

    c.push_back("World");
    std::cout << c << std::endl;

    return 0;
}