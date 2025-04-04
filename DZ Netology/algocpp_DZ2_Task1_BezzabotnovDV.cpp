// Числа Фибоначчи через рекурсивный подсчёт. Сложность O(2^n), память О(1)

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

    return EXIT_SUCCESS;
}