// Задача 1. Наивная хэш-функция для строки

#include <iostream>
#include <Windows.h>

int simple_string_hash(std::string str) {
    int hash = 0;

    for (int i = 0; i < str.length(); i++) {
        hash = hash + static_cast<int>(str[i]);
    }

    return hash;
}

int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    std::string str{'0'};
    do {
        std::cout << "Введите строку (e - выход): ";
        std::cin >> str;
        if (str == "e") break;
        std::cout << "Наивный хэш строки " << str << " = " << simple_string_hash(str) << std::endl;
    } while (str != "e");

    return EXIT_SUCCESS;
}

