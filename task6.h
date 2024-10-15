#ifndef TASK6_H
#define TASK6_H

#include <iostream>
#include "main_transformations.h"

void task6() {

    //В десятичную систему
    double num1 = from_n_to_ten("100101.1", 2);
    double num2 = from_n_to_ten("F4A.3E", 16);
    double num3 = from_n_to_ten("462.51", 8);
    double num4 = from_n_to_ten("101.011", 2);
    double num5 = from_n_to_ten("8E5", 16);
    double num6 = from_n_to_ten("111110.111", 2);

    double result10 = ((num1 + (num2 / num3)) * num4) - (num5 * num6);

    //В шестнадцатеричную систему
    std::string result16 = from_ten_to_n(result10, 16);

    std::cout << "Задание 6 - пройдено" << std::endl;
}

#endif //TASK6_H
