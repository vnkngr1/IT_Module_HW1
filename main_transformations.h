#ifndef MAIN_TRANSFORMATIONS_H
#define MAIN_TRANSFORMATIONS_H

#include <map>
#include <string>
#include <vector>

int charToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    return -1;  // Неправильный символ
}

char intToChar(int num) {
    if (num >= 0 && num <= 9) {
        return num + '0';
    } else if (num >= 10 && num <= 15) {
        return num - 10 + 'A';
    }
    return '\0';  // Неправильное значение
}

std::string from_ten_to_n(double number, int base, int precision = 20) {
    // Разделяем целую и дробную части
    int intPart = static_cast<int>(number);
    double fracPart = number - intPart;

    const char digits[] = "0123456789ABCDEF";

    // Конвертируем целую часть
    std::string convertedIntPart;

    while (intPart > 0) {
        convertedIntPart += digits[intPart % base];  // Добавляем соответствующий символ
        intPart /= base;
    }

    std::reverse(convertedIntPart.begin(), convertedIntPart.end());

    // Конвертируем дробную часть
    std::string convertedFracPart;

    for (int i = 0; i < precision; ++i) {
        fracPart *= base;
        int integerPart = static_cast<int>(fracPart);
        convertedFracPart += digits[integerPart];
        fracPart -= integerPart;

        if (fracPart == 0) break;  // Если дробная часть становится 0, останавливаемся
    }

    // Формируем итоговую строку
    return convertedFracPart.empty() ? convertedIntPart : (convertedIntPart + "." + convertedFracPart);
}

double from_n_to_ten (std::string num, int n) {

    std::string integer = num.substr(0, num.find('.'));
    std::string fraction = num.substr(num.find('.') + 1);

    double result = 0;
    for (int i = 0; i < integer.size(); i++) {
        result += charToInt(integer.at(i)) * pow(n,integer.size() - 1 - i);
    }
    for (int i = 0; i < fraction.size(); i++) {
        result += charToInt(fraction.at(i)) * pow(n,-1 * i - 1);
    }
    return result;
}

std::string from_m_to_n (std::string num, int m, int n) {
    return from_ten_to_n(from_n_to_ten(num, m), n);
}

std::string addBinaryIntegers(const std::string& a, const std::string& b) {
    std::string result = "";  // Результат сложения
    int carry = 0;            // Перенос
    int i = a.size() - 1;     // Индекс для числа a
    int j = b.size() - 1;     // Индекс для числа b

    // Проходим с конца обеих строк
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result += (sum % 2) + '0';
        carry = sum / 2;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

std::string addBinaryFloatingPoint(const std::string& num1, const std::string& num2) {
    // Разделение на целую и дробную части
    std::string intPart1 = num1.substr(0, num1.find('.'));
    std::string fracPart1 = num1.substr(num1.find('.') + 1);

    std::string intPart2 = num2.substr(0, num2.find('.'));
    std::string fracPart2 = num2.substr(num2.find('.') + 1);

    // Выравнивание длины дробной части
    while (fracPart1.size() < fracPart2.size()) {
        fracPart1 += '0';  // Добавляем нули к frac1
    }
    while (fracPart2.size() < fracPart1.size()) {
        fracPart2 += '0';  // Добавляем нули к frac2
    }

    // Переменная переноса
    int carry = 0;

    // Сложение дробных частей
    std::string fractionResult = "";
    int maxSize = std::max(fracPart1.size(), fracPart2.size());

    // Проходим по дробной части с начала
    for (int i = maxSize - 1; i >= 0; --i) {
        int sum = carry;
        if (i < fracPart1.size()) sum += fracPart1[i] - '0';
        if (i < fracPart2.size()) sum += fracPart2[i] - '0';
        fractionResult += (sum % 2) + '0';
        carry = sum / 2;
    }

    std::reverse(fractionResult.begin(), fractionResult.end());

    // Сложение целых частей с учетом возможного переноса
    std::string integerResult = addBinaryIntegers(intPart1, intPart2);
    if (carry) {
        integerResult = addBinaryIntegers(integerResult, "1");
    }

    return integerResult + "." + fractionResult;
}

std::string multiplyBinary(const std::string& num1, const std::string& num2) {

    int point = (num1.size() - num1.find('.')) + (num2.size() - num2.find('.')) - 2;

    std::string new_num1 = num1.substr(0, num1.find('.')) + num1.substr(num1.find('.') + 1);
    std::string new_num2 = num2.substr(0, num2.find('.')) + num2.substr(num2.find('.') + 1);

    std::string result = "0";

    for (int i = new_num2.size() - 1; i >= 0; --i) {
        if (new_num2[i] == '1') {
            std::string temp = new_num1;
            // Добавляем необходимое количество нулей в конец
            temp.append(new_num2.size() - 1 - i, '0');
            result = addBinaryIntegers(result, temp);
        }
    }

    std::string new_result = result.substr(0, result.size() - point) + "." + result.substr(result.size() - point);

    return new_result;
}

#endif //MAIN_TRANSFORMATIONS_H
