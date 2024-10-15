#ifndef TASK4_H
#define TASK4_H

#include <iostream>
#include <ostream>
#include <string>
#include "main_transformations.h"

void task4() {
    std::string num1 = "7A4B.0";
    std::string num2 = "623.5";

    std::string num1_2 = from_m_to_n(num1, 16, 2);
    std::string num2_2 = from_m_to_n(num2, 8, 2);

    std::string result2 = multiplyBinary(num1_2, num2_2);
    double result10 = from_n_to_ten(result2, 2);
    std::string result16 = from_ten_to_n(result10, 16);

    std::cout << "Задание 4 - пройдено" << std::endl;
}

#endif //TASK4_H
