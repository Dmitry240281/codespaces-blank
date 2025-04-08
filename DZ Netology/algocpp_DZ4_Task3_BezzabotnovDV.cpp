// Задача 3*. Удаление первого элемента из изменяемого динамического массива

#include <iostream>
#include <Windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; i++) {
        if (i < logical_size) std::cout << arr[i] << " ";
        else std::cout << "_ ";
    }
    std::cout << std::endl;
}

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int new_cell) {
    std::cout << "logical_size " << logical_size;
    std::cout << "actual_size " << actual_size << std::endl;
    if (actual_size == 0) actual_size = 1;
    if (logical_size < actual_size) {
        logical_size++;
        arr[logical_size - 1] = new_cell;
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
            else if (i == a_s) new_arr[logical_size - 1] = new_cell;
            else new_arr[i] = 0;
        }

        return new_arr;
        delete[] new_arr;
    }
    
}

int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size) {
    logical_size--;
    std::cout << "logical_size " << logical_size << std::endl;
    if (logical_size > actual_size/3) {
        for (int i = 0; i < actual_size; i++) {
            arr[i] = arr[i + 1];
        }
        return arr;
    }
    else {
        actual_size = actual_size / 3;
        int* new_arr = new int[actual_size];
        for (int i = 0; i < actual_size; i++) {
            new_arr[i] = arr[i + 1];
        }
        return new_arr;
        delete[] new_arr;
    }
}

int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

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
    char select = '/';

    while (select != '0') {
        std::cout << "Если надо добавить, нажмите '+' если удалить '-', выйти '0': ";
        std::cin >> select;

        if (select == '+') {
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
        }
        else if (select == '-') {
            std::string del;
            while (del != "n") {
                std::cout << "Удалить первый элемент (y, n)? ";
                std::cin >> del;
                if (del == "y") {
                    if (log_size > 0) {
                        array = remove_dynamic_array_head(array, log_size, act_size);
                        print_dynamic_array(array, log_size, act_size);
                    }
                    else {
                        std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!" << std::endl;
                        break;
                    }
                }
                else if (del == "n") print_dynamic_array(array, log_size, act_size);
                else std::cout << "Ошибка!" << std::endl;
            }
        }
        else if (select == '0') {
            print_dynamic_array(array, log_size, act_size);
            std::cout << "Досвидание!" << std::endl;
            break;
        }    
        else std::cout << "Ошибка!";
    }

    delete[] array;

    return EXIT_SUCCESS;
}