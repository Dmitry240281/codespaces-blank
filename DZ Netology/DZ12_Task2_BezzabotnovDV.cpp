// Задача 2. Чтение массива из файла

#include <iostream>
#include <fstream>
#include <string>

int file(std::string fi) {
    std::ifstream fin(fi);
    int size;
    std::string buff, s;
    if (!fin.is_open()) {
        std::cout << "Видишь файл? А его нет!" << std::endl;
        return 0;
    }

    fin >> buff;
    size = std::stoi(buff);
    int *arr = new int[size];

    for (int i = size-1; i >= 0; i--) {
        fin >> s;
        arr[i] = std::stoi(s);
    }
    std::cout << "Обратный массив из файла: " << fi << " размером: " << size << std::endl;
    for (int j = 0; j < size; j++) std::cout << arr[j] << ' ';
    std::cout  << std::endl;

    delete[] arr;
    fin.close();
}

int main()
{
    setlocale(LC_ALL, "rus");
    std::string fi1 = "in1.txt";
    std::string fi2 = "in2.txt";
    file(fi1);
    file(fi2);

    return 0;
}

