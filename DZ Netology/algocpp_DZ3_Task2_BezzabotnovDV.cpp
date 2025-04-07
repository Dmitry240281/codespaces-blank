// Задача 2. Быстрая сортировка

#include <iostream>

void print_array(int* arr, int s) {
    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < s; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void quick_sort(int* arr, int s) {
    //Указатели в начало и в конец массива
    int left = 0;
    int right = s-1;
    //Центральный элемент массива
    int pivot = arr[s / 2];
    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (arr[left] < pivot) {
            left++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (arr[right] > pivot) {
            right--;
        }
        if (left <= right) {
            int swap = arr[left];
            arr[left] = arr[right];
            arr[right] = swap;
            left++;
            right--;
            //print_array(arr, s);
        }
    } while (left <= right);
    //Рекурсивные вызовы, если осталось, что сортировать
    if (right > 0) {
        //"Левый кусок"
        quick_sort(arr, right + 1);
    }
    if (left < s) {
        //"Првый кусок"
        quick_sort(&arr[left], s - left);
    }
//print_array(arr, s);
}

int main()
{
    setlocale(LC_ALL, "rus");
    int array1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int array2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int array3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int size3 = sizeof(array3) / sizeof(array3[0]);
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size2; i++)
        std::cout << array2[i] << " ";
    std::cout << std::endl;

    quick_sort(array2, size2);
    print_array(array2, size2);

    return EXIT_SUCCESS;
}

