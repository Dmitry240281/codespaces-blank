// Задача 1. Уникальный вектор

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec = { 1, 1, 2, 5, 6, 1, 2, 4 };
    std::cout << "[IN]: ";
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    std::sort(vec.begin(), vec.end()); // сначала сортируем vector

    auto it = std::unique(vec.begin(), vec.end());
    vec.erase(it, vec.end()); // удаляем одинаковые значения
    std::cout << "[OUT]: ";
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

