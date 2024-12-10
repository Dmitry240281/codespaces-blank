// Задача 3. Переворот массива

#include <iostream>

void reverse(int* arr, int size) {
    std::cout << "До функции reverse: ";
    for (int i = 0; i < size; i++) std::cout << arr[i] << ' ';
    std::cout << std::endl;
    int m = size / 2;
    for (int i = 0; i < m; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - i - 1] = temp;
    }
    std::cout << std::endl;
    std::cout << "После функции reverse: ";
    for (int i = 0; i < size; i++) std::cout << arr[i] << ' ';
}

int main()
{
    setlocale(LC_ALL, "rus");
    int arr[] = { 1,2,3,4,5,6,7,8,9,0,-1,-2,-3 };
    int size = sizeof(arr) / sizeof(arr[0]);
    reverse(arr, size);

    return 0;
}

