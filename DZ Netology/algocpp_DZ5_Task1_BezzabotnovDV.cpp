// Задача 1. Вывод пирамиды на массиве

#include <iostream>

class heap {
    int size = 0;
    int* arr = new int[size];
    int index;
public:
    heap(int* arr, int size, int index) {
        this->arr = arr;
        this->size = size;
        this->index = index;
    }

    int root() { return arr[0]; };

    int from_index(int index) {
        return arr[index];
    }

    int left_index(int parant_index) {
        return 2 * parant_index + 1;
    }

    int right_index(int parant_index) {
        return 2 * parant_index + 2;
    }

    int parant_index(int child_index) {
        return (child_index - 1) / 2;
    }

    void print_pyramid()
    {
        int level = 0;
        int i = index;
        while (i != 0) {
            level++;
            i = (i - 1) / 2;
        }
            if (index == 0) {
                std::cout << 0 << " root " << root() << std::endl;
                //k++;
            }
            else if (index % 2 == 0) std::cout << level << " right(" << arr[parant_index(index)] << ") " << arr[right_index(parant_index(index))] << std::endl;
            else std::cout << level << " left(" << arr[parant_index(index)] << ") " << arr[left_index(parant_index(index))] << std::endl;
            //if (i > k * k) k++;
        
    }
};




int main()
{
    setlocale(LC_ALL, "rus");

    int array[] = { 1, 3, 6, 5, 9, 8 };
    int array2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int array3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int size = sizeof(array) / sizeof(array[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int size3 = sizeof(array3) / sizeof(array3[0]);
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; i++)
        std::cout << array[i] << ", ";
    std::cout << std::endl;
    
    std::cout << "Пирамида: " << std::endl;
    for (int i = 0; i < size; i++) {
        heap H(array, size, i);
        H.print_pyramid();
    }
    
    std::cout << "Исходный массив 2: ";
    for (int i = 0; i < size2; i++)
        std::cout << array2[i] << ", ";
    std::cout << std::endl;
    std::cout << "Пирамида 2: " << std::endl;
    for (int i = 0; i < size2; i++) {
        heap H2(array2, size2, i);
        H2.print_pyramid();
    }
    
    std::cout << "Исходный массив 3: ";
    for (int i = 0; i < size3; i++)
        std::cout << array3[i] << ", ";
    std::cout << std::endl;
    std::cout << "Пирамида 3: " << std::endl;
    for (int i = 0; i < size3; i++) {
        heap H3(array3, size3, i);
        H3.print_pyramid();
    }
    
    return EXIT_SUCCESS;
}

