// Задача 3. Динамическая таблица умножения

#include <iostream>

int** create_two_dim_array(int row, int col) {
    int** arr = new int* [row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
    }

    return arr;
}

void print_two_dim_array(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << arr[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

void fill_two_dim_array(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = (i+1) * (j+1);
        }
    }
    print_two_dim_array(arr, row, col);

}

void delete_two_dim_array(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int row = 0;
    int col = 0;
    std::cout << "Введите количество строк: ";
    std::cin >> row;
    std::cout << "Введите количество столбцов: ";
    std::cin >> col;
    int** arr_two = create_two_dim_array(row, col);
    fill_two_dim_array(arr_two, row, col);
    delete_two_dim_array(arr_two, row, col);

    return 0;
}

