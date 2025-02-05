// Задача 2. Счета

#include <iostream>
#include <Windows.h> // используется для ввода и выводв из консоли
    

struct card_account {
    int account_number;
    std::string name;
    float balance;
};

// Функция изменения баланса на карте клиента
void new_balance(card_account& nca) {
    std::cout << "Введите новый баланс: ";
    float new_bal;
    std::cin >> new_bal;
    nca.balance = new_bal;
}

int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    card_account ca;
    std::cout << "Введите номер счёта: ";
    std::cin >> ca.account_number;
    std::cout << "Введите имя владельца: ";
    std::cin >> ca.name;
    std::cout << "Введите баланс: ";
    std::cin >> ca.balance;
        
    new_balance(ca);

    std::cout << "Ваш счёт: " << ca.name << ", " << ca.account_number << ", " << ca.balance;

    return EXIT_SUCCESS;
}

