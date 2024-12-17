// Задача 1. Приветствие

#include <iostream>
#include <Windows.h>
#include <string>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string name;
    std::string fam;
    std::string otch;
    std::string FIO;
    std::cout << "Давайте познакомимся" << std::endl;
    std::cout << "Введите ваше фамилию: ";
    std::cin >> fam;
    std::cout << "Введите ваше имя: ";
    std::cin >> name;
    std::cout << "Введите ваше отчество: ";
    std::cin >> otch;
    FIO = "Здравствуйте, " + fam + " " + name + " " + otch + "!";
    std::cout << FIO << std::endl;

    return 0;
}

