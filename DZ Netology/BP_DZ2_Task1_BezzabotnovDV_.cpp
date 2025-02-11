// Задача 1. Калькулятор двух чисел

#include <iostream>

class Calculator {
    double num1, num2; // приватные поля класса
public:
    Calculator(double num1, double num2) { // канструкт с инициализацией
        this->num1 = num1;
        this->num2 = num1;
    }
    bool set_num1(double num1) { // метод проверки первого введенного пользователем поля на 0
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        else return false;
    }
    bool set_num2(double num2) { // метод проверки второго введенного пользователем поля на 0
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        else return false;
    }
    double add() { // метод сложения
        return num1 + num2;
    }
    double multiply() { // метод умножения
        return num1* num2;
    }
    double subtract_1_2() { // метод вычитания 1-ого из 2-ого
        return num2 - num1;
    }
    double subtract_2_1() { // метод вычитания 2-ого из 1-ого
        return num1 - num2;
    }
    double divide_1_2() { // метод деления 1-ого на 2-ое
        return num1 / num2;
    }
    double divide_2_1() { // метод деления 2-ого на 1-ое
        return num2 / num1;
    }

};

int main()
{
    setlocale(LC_ALL, "rus");
    double n1{1}, n2{1};
    Calculator calc(n1, n2); // создаем объект класса 
    while (true) { // цикл работы в программе
                              // инициализируем 1-ую переменную
        std::cout << "Введите num1: ";
        std::cin >> n1;
        while (calc.set_num1(n1) == false) {  // проверяем её на 0
            std::cout << "Неверный ввод!" << std::endl;
            std::cout << "Введите num1: "; // если да то просим еще раз ввести значение 1 переменной
            std::cin >> n1;
        }
                             // инициализируем 1-ую переменную
        std::cout << "Введите num2: ";
        std::cin >> n2;
        while (calc.set_num2(n2) == false) { // проверяем её на 0
            std::cout << "Неверный ввод!" << std::endl;
            std::cout << "Введите num2: "; // если да то просим еще раз ввести значение 2 переменной
            std::cin >> n2;
        }

        // Выдаем результаты работы калькулятора
        std::cout << "num1 + num2 = " << calc.add() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;

    }
    return EXIT_SUCCESS;
}

