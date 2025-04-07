// Задача 1. Сортировка слиянием

#include <iostream>

void print_array(int* arr, int s) {
    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < s; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
/* Пузырьковый метод
void pusir(int* arr, int s) {
    for (int i = 0; i < s - 1; i++)
    {
        for(int j = 0; j < s-i-1; j++)
            if (arr[j] > arr[j + 1]) {
                int swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
    }
    print_array(arr, s);
}
*/

int* merge(int* arr1, int* arr2, int a, int b) {
    int c = a + b;
    int* arr3 = new int[c];
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;
    while (i1 < a || i2 < b) {
        if (i1 == a) // arr1 закончился
        {
            arr3[i3] = arr2[i2];
            i2++;
        }
        else if (i2 == b) // arr2 закончился
        {
            arr3[i3] = arr1[i1];
            i1++;
        }
        else {
            if (arr1[i1] < arr2[i2]) {
                arr3[i3] = arr1[i1];
                i1++;
            }
            else {
                arr3[i3] = arr2[i2];
                i2++;
            }
        }
        i3++;
    }
    return arr3;

    delete[] arr3;
}

int* merge_sort(int* arr, int s) {
    if(s==1) return arr;
    else {
        int h = s / 2;
        int h2 = s - h;
        int* left = new int[h];
        for (int i = 0; i < h; i++)
            left[i] = arr[i];
        int* right = new int[h2];
        int k = 0;
        for (int j = h; j < s; j++) {
            right[k] = arr[j];
            k++;
        }

        int* left_sorted = merge_sort(left, h);
        int* right_sorted = merge_sort(right, h2);

        int* arr_sort = merge(left_sorted, right_sorted, h, h2);
        
        return arr_sort;

        delete[] left;
        delete[] right;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int array1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int array2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int array3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    
    int size = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int size3 = sizeof(array3) / sizeof(array3[0]);
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size3; i++)
        std::cout << array3[i] << " ";
    std::cout << std::endl;

    int* array_sort = merge_sort(array3, size3);

    print_array(array_sort, size3);

    return EXIT_SUCCESS;
}

