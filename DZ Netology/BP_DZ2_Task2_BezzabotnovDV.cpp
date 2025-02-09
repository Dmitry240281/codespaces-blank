// Задача 2. Счётчик

#include <iostream>
#include <Windows.h>

class Counter {
    int value;
public:
    Counter() { value = 1; count_w(value); }  // конструкт если пользователь не ввел значение value = 1
    Counter(int value) { this->value = value; count_w(value); } // конструкт если пользователь ввел значение
    void count_plus(int &value) { value++; } // метод счетчика прибавления значения по ссылке
    void count_minus(int &value) { value--; } // метод счетчика вычитания значения по ссылке
    void count_print(int value) { std::cout << value << std::endl; } // метод выдачи значения

    int count_w(int value) { // метод управления счетчиков по средством введения команд
        char ent; // переменная команды которую вводит пользователь
        while (true) {
            std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
            std::cin >> ent;
            if (ent == '+') {
                count_plus(value);
            }
            else if (ent == '-') {
                count_minus(value);
            }
            else if (ent == '=') {
                count_print(value);
            }
            else if (ent == 'х') {
                std::cout << "Счетчик завершен" << std::endl;
                return EXIT_SUCCESS;
            }
        }
    }
};

int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    std::string ques;
    int val;
    while (true) {  // цикл меню выбора способа ввода начального значения счетчика
        std::cout << "Вы хотите указать начальное значение счётчика? Введите 'да', 'нет' или 'выход': ";
        std::cin >> ques;
        if (ques == "да") {  // выбор ручного ввода значения счетчика
            std::cout << "Введите начальное значение счётчика: ";
            std::cin >> val;
            Counter count(val);
        }
        else if (ques == "нет") { // выбор без ввода значения счетчика
            Counter count2;
        }
        else if (ques == "выход") {  // выход из цикла
            std::cout << "До свидания!" << std::endl;
            return EXIT_SUCCESS;
        } 
        else std::cout << "Неправильный ввод" << std::endl; // если пользователь ввел неправильно
    }
    return EXIT_SUCCESS;
}

