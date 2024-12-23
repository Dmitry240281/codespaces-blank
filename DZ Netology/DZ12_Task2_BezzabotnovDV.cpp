// Задача 2. Чтение массива из файла

#include <iostream>
#include <fstream>
#include <string>

int reverse(int* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - i - 1] = temp;
    }
    return *arr;
}

int file(std::string fi) {
    std::ifstream fin(fi);
    int size;
    std::string buff, s;
    if (!fin.is_open()) {
        std::cout << "Файл не нейден. Проверьте наличие и название файла" << std::endl;
        return 0;
    }

    fin >> buff;
    size = std::stoi(buff);
    int *arr = new int[size];

    for (int i = 0; i < size; i++) {
        fin >> s;
        arr[i] = std::stoi(s);
    }
    reverse(arr, size);
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

    return EXIT_SUCCESS;
}

