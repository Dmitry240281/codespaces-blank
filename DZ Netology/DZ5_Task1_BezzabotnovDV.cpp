/* Задача 1. Вывод массива на экран
Напишите программу, которая создаёт массив целых чисел из 10 элементов и 
выводит на экран все элементы массива через запятую и пробел(, ).
Придумайте сами числа для заполнения массива.
*/

#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    const int size = 10;
    int arr[size] = { 1,2,0,78,34,3,7,11,51,90 };
    std::cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i==size-1) break;
        std::cout << ", ";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
