// Задача 2. Настоящая хэш-функция для строки

#include <iostream>
#include <Windows.h>
#include <cmath>

double  real_string_hash(std::string str, int p, int n) {
    double  hash = 0;
    for (int i = 0; i < str.length(); i++) {
        int c = static_cast<int>(str[i]);
        hash += pow(p, i) * c;
        
    }
    hash = fmod(hash, static_cast<int>(n));
    return hash;
}

int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    std::string str{ '0' };
    int p = 0;
    int n = 0;

    std::cout << "Введите p (простое число): ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;

    do {
        std::cout << "Введите строку (e - выход): ";
        std::cin >> str;
        if (str == "e") break;
        std::cout << "Наивный хэш строки " << str << " = " << real_string_hash(str, p, n) << std::endl;
    } while (str != "e");

    return EXIT_SUCCESS;
}

