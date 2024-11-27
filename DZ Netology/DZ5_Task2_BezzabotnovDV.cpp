/* Задача 2. Максимум и минимум
Напишите программу, которая создаёт массив целых чисел из 10 элементов, 
выводит на экран все элементы массива, находит минимальный и 
максимальный элементы массива и выводит их на экран.
Числа для заполнения массива придумайте сами.
*/
#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    const int size = 10;
    int max_num, min_num;
    int arr[size] = { 1,2,-1,78,95,3,7,11,51,90 };
    std::cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i == size - 1) break;
        std::cout << ", ";
    }

    std::cout << std::endl;

    // Находим максимальное значение
    max_num = arr[0];
    for (int m = 1; m < size; m++) {
        if (max_num < arr[m]) max_num = arr[m];
    }
    std::cout << "Максимальное значение: " << max_num;

    std::cout << std::endl;

    // Находим минимальное значение
    min_num = arr[0];
    for (int k = 1; k < size; k++) {
        if (min_num > arr[k]) min_num = arr[k];
    }
    std::cout << "Минимальное значение: " << min_num;

    std::cout << std::endl;

    return EXIT_SUCCESS;
}



