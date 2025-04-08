// Задача 2. Добавление в изменяемый динамический массив

#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; i++) {
        if (i < logical_size) std::cout << arr[i] << " ";
        else std::cout << "_ ";
    }
    std::cout << std::endl;
}

int* append_to_dynamic_array(int* arr, int &logical_size, int &actual_size, int new_cell) {
    
    if (logical_size < actual_size) {
        logical_size++;
        arr[logical_size -1] = new_cell;
        return arr;
    }
    else {
        int a_s = actual_size;
        actual_size = actual_size * 2;
        logical_size++;
        int* new_arr = new int[actual_size];
        for (int i = 0; i < actual_size; i++) {
            if (i < a_s) {
                new_arr[i] = arr[i];
            }
            else if(i == a_s) new_arr[logical_size-1] = new_cell;
            else new_arr[i] = 0;
        }

        return new_arr;
        delete[] new_arr;
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

    for (int i = 0; i < act_size; i++) {
        if (i < log_size) {
            std::cout << "Введите arr[" << i << "]: ";
            std::cin >> array[i];
        }
        else array[i] = 0;
    }


    print_dynamic_array(array, log_size, act_size);

    int new_cell{ 1 };
    while (new_cell != 0) {
        std::cout << "Введите элемент для добавления (0 - выход): ";
        std::cin >> new_cell;
        if (new_cell != 0) {
            array = append_to_dynamic_array(array, log_size, act_size, new_cell);
            print_dynamic_array(array, log_size, act_size);
        }
    }

    std::cout << "Спасибо! Ваш массив: ";
    for (int i = 0; i < act_size; i++) {
        if (i < log_size) std::cout << array[i] << " ";
        else std::cout << "_ ";
    }
    std::cout << std::endl;
    
    delete[] array;

    return EXIT_SUCCESS;
}
