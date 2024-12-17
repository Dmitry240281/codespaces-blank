// Задача 2. Угадайка

#include <iostream>
#include <Windows.h>
#include <string>

std::string _compare(std::string sec) {
    std::string word;
    do {
        std::cout << "Угадай ягоду: ";
        std::cin >> word;
        if (word.compare(sec) != 0) std::cout << "Неправильно" << std::endl;
    } while (word.compare(sec) != 0);
    std::string otv = "Правильно, вы угадали: " + word;
    return otv;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    std::string secret{ "малина" };
    std::cout << "Давай поиграем" << std::endl;

    std::cout << _compare(secret) << std::endl;

    return 0;
}

