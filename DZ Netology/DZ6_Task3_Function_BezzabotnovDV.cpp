// Занятие 6, Функции. Задание 3 Числа Фибоначчи
/*Числа Фибоначчи — элементы числовой последовательности 0, 1,
1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233..., в которой первые два числа равны 0 и 1,
а каждое последующее число равно сумме двух предыдущих чисел.*/

#include <iostream>

int Fibonacci(int a)
{
    if (a == 0)
    {
        return 0;
    }
    else if (a == 1)
    {
        return 1;

    }
    else {
        return a = Fibonacci(a - 1) + Fibonacci(a - 2);
    }
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");
    int a = 0;
    std::cout << "Введите число: ";
    std::cin >> a;
    std::cout << "Числа Фибоначчи: ";
    for (int i = 0; i < a; i++)
    {
        std::cout << Fibonacci(i) << ' ';
    }
    std::cout << std::endl;

    return 0;
}