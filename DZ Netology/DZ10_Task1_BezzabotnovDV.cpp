// Задача 1. Ввод массива с консоли

#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    int size = 0;
    std::cout << "Пожалуйста, введите размер массива: ";
    std::cin >> size;
    std::cout << std::endl;
    int* arr = new int[size]();
    std::cout << "Введите значения массива: ";
    std::cout << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "arr[" << i << "] = "; 
        std::cin >> arr[i];
    }
    std::cout << std::endl;
    std::cout << "Введённый массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
    delete[] arr;

    return 0;
}

