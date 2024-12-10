// Задача 2. Снова swap

#include <iostream>

void swap(int &x, int &y) {
    ((short*)&x)[1] = ((short*)&y)[0];
    *((short*)&y) = ((short*)&x)[0];
    *((short*)&x) = ((short*)&x)[1];
    ((short*)&x)[1] = 0;
}

int main()
{
    int a = 5, b = 8;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
}

