// Задача 2. Счётчик

#include <iostream>
#include <Windows.h>

class Counter {
    int value;
public:
    Counter() { value = 1; }  // конструкт если пользователь не ввел значение value = 1
    Counter(int value) { this->value = value; } // конструкт если пользователь ввел значение
    void count_plus() { value++; } // метод счетчика прибавления значения по ссылке
    void count_minus() { value--; } // метод счетчика вычитания значения по ссылке
    void count_print() { std::cout << value << std::endl; } // метод выдачи значения
};

int count_w(int value) { // метод управления счетчиков по средством введения команд
    Counter count(value);
    char ent; // переменная команды которую вводит пользователь
    while (true) {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> ent;
        if (ent == '+') {
            count.count_plus();
        }
        else if (ent == '-') {
            count.count_minus();
        }
        else if (ent == '=') {
            count.count_print();
        }
        else if (ent == 'х') {
            std::cout << "До свидания!" << std::endl;
            return EXIT_SUCCESS;
        }
    }
}

int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    std::string ques;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите 'да', 'нет': ";
    std::cin >> ques;
    if (ques == "да") {  // выбор ручного ввода значения счетчика
        int val;
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> val;
        count_w(val);
    }
    else if (ques == "нет") { // выбор без ввода значения счетчика
        int val1 = 1;
        count_w(val1);
    }
    return EXIT_SUCCESS;
}

