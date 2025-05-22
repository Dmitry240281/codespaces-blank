// Задача 2. Таблица
// Нужно написать шаблонный класс для двумерного массива (таблицы). 
// Все ячейки таблицы имеют один и тот же тип данных T.

#include <iostream>

template <typename T>
class Table {
    int r = 0;
    int c = 0;
    T** array = nullptr;
public:
    Table(int r, int c) {
        array = new T * [r];
        for (int i = 0; i < r; i++) {
            array[i] = new T[c];
        }
    }

    Table(const Table& other) : r(other.r), c(other.c) {
        array = new T*[r]; // Выделение новой памяти
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                array[i][j] = other.array[i][j];
            }
        }
    }

    Table& operator=(const Table& other) {
        if (this != &other) {
            for (int i = 0; i < r; i++) {
                delete[] array[i];
            }
            delete[] array;
            array = new T * [r]; // Выделение новой памяти
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    array[i][j] = other.array[i][j];
                }
            }
        }
        return *this;
    }

    void operator[](T* value) {
        array = value;
    }

    T* operator[](int i) {
        return array[i];
    }

    const int Size(int r, int c) {
        int size = r * c;
        return size;
    }
    
    ~Table() {
        for (int i = 0; i < r; i++) {
            delete[] array[i];
        }
        delete[] array;
    }
};

int main()
{
    int row = 2;
    int col = 3;

    auto test = Table<int>(row, col);

    test[0][0] = 4;
    test[0][1] = 1;
    test[0][2] = 10;
    test[1][0] = 2;
    test[1][1] = 5;
    test[1][2] = 11;
    std::cout << "Element: " << test[0][0];
    std::cout << std::endl;

    std::cout << "Table size: " << test.Size(row, col) << std::endl;

    std::cout << "Table: " << std::endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << test[i][j] << (j==col-1 ? "" : ", ");
        }
        std::cout << std::endl;
    }

    int row1 = 3;
    int col1 = 4;

    auto test1 = Table<int>(row1, col1);

    test1[0][0] = 4;
    test1[0][1] = 1;
    test1[0][2] = 10;
    test1[0][3] = 22;
    test1[1][0] = 2;
    test1[1][1] = 5;
    test1[1][2] = 11;
    test1[1][3] = 31;
    test1[2][0] = 3;
    test1[2][1] = 6;
    test1[2][2] = 12;
    test1[2][3] = 44;

    test = test1;

    std::cout << "Table new: " << std::endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            std::cout << test1[i][j] << (j == col1 - 1 ? "" : ", ");
        }
        std::cout << std::endl;
    }

    return 0;
}

