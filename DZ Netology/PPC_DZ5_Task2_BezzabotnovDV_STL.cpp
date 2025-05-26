// Задача 2. Удаление дубликатов

#include <iostream>
#include <set>

int main()
{
    setlocale(LC_ALL, "rus");
    int size, elem;
    std::set<int> set_elem;
    std::cout << "Введите количество элементов: ";
    std::cin >> size;
    for (int i = 0; i < size; i++) {
        std::cout << "Введите эелемент " << i+1 << ": ";
        std::cin >> elem;
        set_elem.insert(elem);
    }
    std::cout << "[OUT]: " << std::endl;

    for (auto i = set_elem.rbegin(); i != set_elem.rend(); i++)
        std::cout << *i << std::endl;
    
    return 0;
}

