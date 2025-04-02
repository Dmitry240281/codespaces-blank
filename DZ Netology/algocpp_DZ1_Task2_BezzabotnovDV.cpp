// algocpp_DZ1_Task2_BezzabotnovDV.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
// Бинарный поиск
int Binary_search(int* arr, int s, int ent) {
    int left, right, middle;
    left = 0;  // Задаем границы интервала поиска
    right = s - 1;
    int elemarr = -1;
        if (ent > arr[right]) return right;
        else {
            while (left <= right) {
                middle = (left + right) / 2; // вычисляем срединное значение массива
                if (arr[middle] == ent) {
                    elemarr = middle;
                    left = middle + 1; // ищем справа
                }
                else if (arr[middle] > ent) {
                    right = middle - 1; // ищем слева
                }
                else if (arr[middle] < ent) {
                    left = middle + 1; // ищем справа
                }
            }
            return elemarr;
        }
    
}

int main()
{
    setlocale(LC_ALL, "rus");
    int array[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int size;
    
    size = (sizeof(array) / sizeof(array[0]));
    int ent;
    //std::cout << "Массив: [";
    //for (int i = 0; i < size; i++) std::cout << array[i] << " ";
    //std::cout << "]" << std::endl;
    //std::cout << "Размер массива " << size << std::endl;
    std::cout << "Введите точку отсчёта: ";
    std::cin >> ent;

    int bs = -1;
    int en = ent;
    bs = Binary_search(array, size, ent);
    if (bs >=0 ) std::cout << "Количество элементов в массиве больших, чем " << ent << ": " << ((size - 1) - bs) << std::endl;
    else {
        do {
            bs = Binary_search(array, size, en);
            if (bs < 0) {
                en++;
            }
            else break;
        } while (bs < 0);
        std::cout << "Количество элементов в массиве больших, чем " << ent << ": " << (size - bs) << std::endl;
    }

    return EXIT_SUCCESS;
}

