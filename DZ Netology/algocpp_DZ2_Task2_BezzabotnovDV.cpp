/// Числа Фибоначчи c использованием массива. Массив ускоряет работу. Алгосложность составляет O(n) и память O(n);

#include <iostream>

double* Fibonacci(double* arr, int size)
{
    if (size == 0)
    {
        arr[0] = 0;
        return arr;
    }
    else if (size == 1)
    {
        arr[0] = 0;
        arr[1] = 1;
        return arr;
    }
    else {
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i < size; i++)
            arr[i] = arr[i - 1] + arr[i - 2];
        return arr;
    }
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");
    
    int a = 0;
    std::cout << "Введите число: ";
    std::cin >> a;
    double* array = new double[a];
    Fibonacci(array, a);
    std::cout << "Числа Фибоначчи: ";
    for (int i = 0; i < a; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
