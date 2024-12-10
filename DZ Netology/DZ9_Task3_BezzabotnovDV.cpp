// Задача 3. Переворот массива

#include <iostream>

void reverse(int* arr, int size) {
    int r_arr[80];
    std::cout << "До функции reverse: ";
    for (int i=0; i < size; i++) std::cout << arr[i] << ' ';
    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
    r_arr[i] = arr[size - 1 - i]; // меняем местами
    }
    std::cout << "После функции reverse: ";
    for (int i=0; i < size; i++) std::cout << r_arr[i] << ' ';
}

int main()
{
    setlocale(LC_ALL, "rus");
    //int arr[] = { 3,5,67,81,3,65,4,3,9,0 };
    int arr[] = { 1,2,3,4,5,6,7,8,9 };
    int size = sizeof(arr) / sizeof(arr[0]);
    reverse(arr, size);
    
    return 0;
}

