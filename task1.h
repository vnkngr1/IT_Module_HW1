#ifndef TASK1_H
#define TASK1_H

#include <iostream>
#include <ostream>
#include <string>
#include "main_transformations.h"

void task1() {
    std::string num = "100101110110.111";
    double num10 = from_n_to_ten(num, 2);
    std::string num8 = from_ten_to_n(num10, 8);
    std::string num16 = from_m_to_n(num8, 8, 16);
    std::string num2 = from_m_to_n(num16, 16, 2);
    if (num2 != num) {
        std::cout << "Задание 1 - ошибка" << std::endl;
    }
    else {
        std::cout << "Задание 1 - пройдено" << std::endl;
    }
}

#endif //TASK1_H
