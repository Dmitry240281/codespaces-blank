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

    return 0;
}

