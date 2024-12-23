// Задача 3. Пользовательский массив в файл

#include <iostream>
#include <fstream>

int reverse(int* arr, int size) {
    for (int i = 0; i < size/2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - i - 1] = temp;
    }
    return *arr;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    int* arr = new int[size];
    std::cout << "Введите лементы массива arr[]: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "arr[" << i << "] = "; 
        std::cin >> arr[i];
    }
    std::cout << std::endl;
    reverse(arr, size);
    std::ofstream fout("out.txt");
    if (!fout.is_open()) {
        std::cout << "Файл не нейден. Проверьте наличие и название файла";
        return 1;
    }
    fout << size << "\n";
    std::cout << "После функции reverse: ";
    for (int i = 0; i < size; i++) std::cout << arr[i] << ' ';
    for (int i = 0; i < size; i++) fout << arr[i] << ' ';
    std::cout << std::endl;
    std::cout << "Результат записан в файл: out.txt";


    delete[] arr;
    fout.close();
    return EXIT_SUCCESS;

}

