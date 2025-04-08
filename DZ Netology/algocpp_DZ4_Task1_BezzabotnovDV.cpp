// Задача 1. Вывод изменяемого динамического массива

#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; i++) {
        if (i < logical_size) std::cout << arr[i] << " ";
        else std::cout << "_ ";
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int act_size{ 0 }, log_size{ 0 };

    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> act_size;
    std::cout << "Введите логический размер массива: ";
    std::cin >> log_size;

    if (log_size > act_size) {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
        return 0;
    }

    int* array = new int[act_size];

    for (int i = 0; i < log_size; i++) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> array[i];
    }

    print_dynamic_array(array, log_size, act_size);

    delete[] array;

    return EXIT_SUCCESS;
}

