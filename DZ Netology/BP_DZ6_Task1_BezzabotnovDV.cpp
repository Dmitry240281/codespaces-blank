// Задача 1. Препроцессорные директивы
#define MODE 1
#ifndef MODE
#error Необходимо определить MODE
#else

#include <iostream>
#if MODE==1
int add(int x, int y) {
    return x + y;
}
#endif

int main()
{
    setlocale(LC_ALL, "rus");
#if MODE==0
    std::cout << "Работаю в режиме тренировки." << std::endl;
#elif MODE==1
    int i, j;
    std::cout << "Работаю в боевом режиме." << std::endl;
    std::cout << "Введите число 1: ";
    std::cin >> i;
    std::cout << "Введите число 2: ";
    std::cin >> j;
    std::cout << "Результат сложения: " << add(i, j) << std::endl;

    std::cout << "Неизвестный режим. Завершение работы." << std::endl;
#endif
#endif
}


  