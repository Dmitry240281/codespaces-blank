//Задача 1. Вывод файла

#include <iostream>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "rus");
    std::string buff;
    std::ifstream fin("in.txt");

    if (!fin.is_open()) {
        std::cout << "Файл не нейден. Проверьте наличие и название файла" << std::endl;
        return 1;
    }

    while (fin >> buff) {
        std::cout << buff << std::endl;
        if (fin.eof()) break;
    }
    fin.close();

    return EXIT_SUCCESS;
}

