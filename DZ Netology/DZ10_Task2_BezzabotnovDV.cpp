// Задача 2. Создатель массивов

#include <iostream>

double* create_array(int size) {
    double* arr = new double[size]();
    return arr;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int size = 0;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    double* ext_arr = create_array(size);
    std::cout << "Массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << ext_arr[i] << ' ';
    }
    
    delete[] ext_arr;

    return 0;
}

