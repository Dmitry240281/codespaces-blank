// Задача 1. Считающая функция

#include <iostream>
static int i = 1;
void counting_function() {
    std::cout << "Количество вызовов функции counting_function(): " << i << std::endl;
    i++;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");
    for (int i = 0; i < 15; i++)
    {
        counting_function();
    }
}

