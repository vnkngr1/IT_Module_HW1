#ifndef TASK2_H
#define TASK2_H

#include <iostream>
#include <string>
#include "main_transformations.h"

void task2() {
    //создаем 16
    std::string num16 = "2C.4F";

    //16 -> 2
    std::string num2 = from_m_to_n(num16, 16, 2);

    //16 -> 10
    double num10 = from_n_to_ten(num16, 16);

    //10 -> 8
    std::string num8_10 = from_ten_to_n(num10, 8);

    //2 -> 8
    std::string num8_2 = from_m_to_n(num2, 2, 8);

    //проверка
    if (num8_10 != num8_2) {
        std::cout << "Задание 2 - ошибка" << std::endl;
    }
    else {
        std::cout << "Задание 2 - пройдено" << std::endl;
    }
}

#endif //TASK2_H
