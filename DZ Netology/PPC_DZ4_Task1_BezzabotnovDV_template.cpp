// Задача 1. Возведение в квадрат
//Нужно реализовать шаблонную функцию возведения в квадрат, 
// которая работает не только с простыми числами, но и с 
// векторами.Для этого создайте две реализации шаблонной функции.

#include <iostream>
#include <vector>

template <typename T>
T square(T a) {
    return a * a;
}

template <typename T>
T* square(T* a) {
    return a * a;
}


int main()
{
    setlocale(LC_ALL, "rus");
    int x;
    std::cout << "Введите число: ";
    std::cin >> x;
    std::cout << "[IN]: " << x << std::endl;
    std::cout << "[OUT]: " << square(x) << std::endl;

    std::cout << "Vector: " << std::endl;
    std::cout << "[IN]: ";
    std::vector<int> vec{ -1, 4, 8 };    
    for (auto i = vec.begin(); i != vec.end(); i++) {
        std::cout << *i << (i == vec.end() - 1 ? "" : ", ");
    }
    std::cout << std::endl;
    std::cout << "Square of vector: " << std::endl;
    std::cout << "[OUT]: ";
    for (auto i = vec.begin(); i != vec.end(); i++) {
        std::cout << square(*i) << (i == vec.end() - 1 ? "" : ", ");
    }
    return 0;
}

