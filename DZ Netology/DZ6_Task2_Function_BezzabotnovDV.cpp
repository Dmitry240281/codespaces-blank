// Занятие 6, Функции. Задание 2

#include <iostream>

void degree(int volue, int power)
{
    setlocale(LC_ALL, "rus");
    int result = 1;
    for (int i = 0; i < power; i++)
    {
        result *= volue;
    }
    std::cout << volue << " в степени " << power << " = " << result << std::endl;
}

int main(int argc, char** argv)
{
    degree(5, 2);
    degree(3, 3);
    degree(4, 4);

    return 0;
}
