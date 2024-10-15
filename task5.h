#ifndef TASK5_H
#define TASK5_H

#include <iostream>
#include "main_transformations.h"

void task5() {

    //В десятичную систему
    double num1 = from_n_to_ten("4D.7B", 16);
    double num2 = from_n_to_ten("25.12", 8);
    double num3 = from_n_to_ten("101110.1101", 2);
    double num4 = from_n_to_ten("111001.01", 2);
    double num5 = from_n_to_ten("C2A.0", 16);
    double num6 = from_n_to_ten("1011010.011", 2);

    double result10 = ((num1 + num2) * (num3 - num4)) / (num5 + num6);

    //В шестнадцатеричную систему
    std::string result16 = "-" + from_ten_to_n(-1 * result10, 16);

    std::cout << "Задание 5 - пройдено" << std::endl;

}

#endif //TASK5_H
