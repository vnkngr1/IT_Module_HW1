#ifndef TASK3_H
#define TASK3_H
#include <string>
#include "main_transformations.h"

void task3() {
    std::string num1 = "111001011.1011";
    std::string num2 = "1011100.11";

    std::string summary = addBinaryFloatingPoint(num1, num2);

    std::string summary16 = from_m_to_n(summary, 2, 16);

    double differecne = (from_n_to_ten("A14B.0", 16) - from_n_to_ten(summary16, 16));

    std::string differecne2 = from_ten_to_n(differecne, 2);

    std::cout << "Задание 3 - пройдено" << std::endl;
}

#endif //TASK3_H
