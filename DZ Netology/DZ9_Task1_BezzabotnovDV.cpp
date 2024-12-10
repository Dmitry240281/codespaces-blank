// Задача 1. Вывод массива

#include <iostream>

void print(int* arr, int size) {
    int i;
    for (i = 0; i < size; i++) std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

int main()
{
    int ar1[] = { 57, 25, 4 };
    int ar2[] = { 125, 16, 5, 19, 51 };
    int ar3[] = { 1, 5, 9, 3, 8, 32 };
    print(ar1, 3);
    print(ar2, 5);
    print(ar3, 6);

    return 0;
}

