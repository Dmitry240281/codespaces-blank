/*Упрощённая консольная реализация игры «Жизнь», 
придуманная английским математиком Джоном Конвеем в 1970 году.*/

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

// Глобальные переменные
int gv_row = 0;
int gv_col = 0;
int gv_itaration = 1;

// Функция создания нового массива 
char** f_create_new_array(int vf_row, int vf_col) {
    // отводим часть памяти для двумерного массива arr
    char** arrf = new char* [vf_row]; // сначала память для значение (**) строк row массива arr
    for (int i = 0; i < vf_row; i++) {
        arrf[i] = new char[vf_col]; // память для ячеек col в каждой строке массива arr
    }
    // заполняем массив "-"
    for (int i = 0; i < vf_row; i++) {
        for (int j = 0; j < vf_col; j++) {
            if (i == 0 || i == vf_row-1 || j == 0 || j == vf_col-1) arrf[i][j] = '/'; // крайние строки и столбци заполняем '/'
            else arrf[i][j] = '-'; // внутреннюю область заполняем '-'
        }
    }
    return arrf;
}

// Заполняем массив данными из файла с увеличенным количеством строк и столбцов на 2
char** f_first_array() {
    std::ifstream filein("in.txt");
    
    std::string buff;
    if (!filein.is_open()) {
        std::cout << "Файл не нейден. Проверьте наличие и название файла" << std::endl;
        return 0;
    }
    filein >> buff;
    gv_row = std::stoi(buff)+2; // перопередляем глобальные переменную row + 2
    filein >> buff;
    gv_col = std::stoi(buff)+2; // перопередляем глобальные переменную col + 2
    
    char** arrf_first = f_create_new_array(gv_row, gv_col); // создаем первый массив

    while (!filein.eof()) {
        for (int i = 0; i < 1; i++) {
            filein >> buff;
            int m = stoi(buff);
            for (int j = 0; j < 1; j++) {
                filein >> buff;
                int n = stoi(buff);
                arrf_first[m+1][n+1] = '*';
            }
        }
    }
    return arrf_first;
    filein.close();
}

// Функция подсчета живых клеток в соседних ячейках
int f_local_live(char** arr, int fv_row, int fv_col) {
    int live_neighbours = 0;
         for (int fro = fv_row-1; fro <= fv_row+1; fro++) {
            for (int fco = fv_col-1; fco <= fv_col+1; fco++) {
                if (arr[fro][fco] == '/') continue; // если точка находится на краю массива и соседняя ячейка - '/' цикл пропускает ход
                if ((fro == fv_row) && (fco == fv_col)) continue; // если точка центральная то цикл пропускает ход
                if (arr[fro][fco] == '*') live_neighbours++; // если соседняя тоска - '*' пиробавляется в переменную live_neighbours
            }
        }
    return live_neighbours;
}

// Подсчет сколько всего живых клеток в массиве
int f_live_all(char** arr, int fv_row, int fv_col) {
    int live_all = 0;
    for (int i = 1; i < fv_row - 1; i++) {
        for (int j = 1; j < fv_col - 1; j++) {
            if (arr[i][j] == '*') live_all++;
        }
    }
    return live_all;
}

// Вывод массива
void f_print_array(char** arr, int fv_row, int fv_col, int fv_live_all) {
    for (int i = 1; i < fv_row-1; i++) {
        for (int j = 1; j < fv_col-1; j++) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "Поколение: " << gv_itaration << ' ' << "Живых клеток: " << fv_live_all << std::endl;
}

// удаление массивов из памяти
void f_delete_array(char** arrf, int fv_row, int fv_col) {
    for (int i = 0; i < fv_row; i++) {
        delete[] arrf[i]; // удаляем в обратном порядке, сначала ячеки (col) массива arr
    }
    delete[] arrf; // потом удаляем строки row
}

// Рекурсивная функция обновляет пространство
char** f_recursion_arr(char** arr_live, int fv_row, int fv_col) {
    char** arrf_liven = f_create_new_array(fv_row, fv_col);
    int vf_status = 0;
    for (int i = 1; i < fv_row - 1; i++) {
        for (int j = 1; j < fv_col - 1; j++) {
            int live_n = f_local_live(arr_live, i, j);
            if (arr_live[i][j] == '-' && live_n == 3) { // Если в пустой (мёртвой) клетке, рядом с которой ровно три живых клетки, зарождается жизнь.
                arrf_liven[i][j] = '*'; 
                vf_status++;
            }
            else if (arr_live[i][j] == '*' && (live_n == 2 || live_n == 3)) arrf_liven[i][j] = '*'; // Если у живой клетки есть две или три живых соседки, то эта клетка продолжает жить.
            else if (arr_live[i][j] == '*' && (live_n < 2 || live_n > 3)) { // если соседей меньше двух или больше трёх, клетка умирает «от одиночества» или «от перенаселённости»
                arrf_liven[i][j] = '-';
                vf_status++;
            }
            else arrf_liven[i][j] = '-'; // мертвое остается мертвым
        }
    }
    int vf_live_all = f_live_all(arrf_liven, fv_row, fv_col);
    gv_itaration++;
    f_print_array(arrf_liven, fv_row, fv_col, vf_live_all);
    Sleep(100);
    if (vf_status == 0) {                                                           // Если в мире ни чего не меняется то программа останавливается
        std::cout << "Поздравляю! Мир стабилен. Игра закончена." << std::endl;
        return EXIT_SUCCESS;
    }
    else if (vf_live_all == 0) {                                                    // Если живых клеток больше нет - программа останавливается
        std::cout << "Соболезную! Все клетки умерли. Игра закончена." << std::endl;
        return EXIT_SUCCESS;
    }
    else if (gv_itaration == 200) {                                                 // Если количество итераций превышает 200 - программа останавливается
        std::cout << "Слишком много поколений. Игра остановлена." << std::endl;
        return EXIT_SUCCESS;
    }
    else return f_recursion_arr(arrf_liven, fv_row, fv_col); // запускаем данную функцию повторно
    f_delete_array(arrf_liven, fv_row, fv_col);
}

int main()
{
    setlocale(LC_ALL, "rus");
    char** m_arr = f_first_array();
    int vm_liveall = f_live_all(m_arr, gv_row, gv_col);
    f_print_array(m_arr, gv_row, gv_col, vm_liveall);
    char** arr_liveit = f_recursion_arr(m_arr, gv_row, gv_col);
    f_delete_array(m_arr, gv_row, gv_col);
}