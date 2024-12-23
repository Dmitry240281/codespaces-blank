// Задача 4. Считывание двумерного массива из файла

#include <iostream>
#include <fstream>
#include <string>

int** create_two_dim_array(int row, int col) {
    // отводим часть памяти для двумерного массива arr
    int** arr = new int* [row]; // сначала память для значение (**) строк row массива arr
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col]; // память для ячеек col в каждой строке массива arr
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

void delete_two_dim_array(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        delete[] arr[i]; // удаляем в обратном порядке, сначала ячеки (col) массива arr
    }
    delete[] arr; // потом удаляем строки row
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::ifstream fin("in.txt");
    int row, col;
    std::string buff, s;
    if (!fin.is_open()) {
        std::cout << "Файл не нейден. Проверьте наличие и название файла" << std::endl;
        return 0;
    }
    fin >> buff;
    row = std::stoi(buff);
    fin >> buff;
    col = std::stoi(buff);
    std::cout << "Двумерный массив из файла in.txt: " << std::endl;
    std::cout << "row: " << row << std::endl << "col: " << col << std::endl;

    int** arr_two = create_two_dim_array(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = col - 1; j >= 0; j--) {
            fin >> s;
            arr_two[i][j] = std::stoi(s);
        }
    }

    print_two_dim_array(arr_two, row, col);
    delete_two_dim_array(arr_two, row, col);
    fin.close();
    return EXIT_SUCCESS;
}

