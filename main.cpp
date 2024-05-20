#include <iostream>

#include "text.hpp"

int main() {
    std::cout << "Начало программы!" << std::endl;

    ARylova::Text a = "123";
    ARylova::Text b = "123";
    ARylova::Text c = "Привет";
    ARylova::Text d = "Мир";
    ARylova::Text e = "Мир";

    a = e;
    std::cout << a << std::endl;

    if (d == e) {
        std::cout << "Равны" << std::endl;
    }

    if (a != c) {
        std::cout << "Не равны"<< std::endl;
    }

    std::cout << c + d << std::endl;

    std::cout << a.at(2) << std::endl;

    c.push_back("Мир");
	c.push_back('1');
    std::cout << c << std::endl;

    return 0;
}
