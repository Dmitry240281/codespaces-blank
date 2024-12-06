// Задача 2. Одинаковые, но разные функции

#include <iostream>

namespace mat_sum {
    int calc(int x, int y) {
        return x + y;
    }
}

namespace mat_sub {
    int calc(int x, int y) {
        return x - y;
    }
}

namespace mat_mul {
    int calc(int x, int y) {
        return x * y;
    }
}

namespace mat_div {
    int calc(int x, int y) {
        return x / y;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int x{ 6 };
    int y{ 9 };
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "Сложение: " << mat_sum::calc(x, y) << std::endl;
    std::cout << "Вычитание: " << mat_sub::calc(x, y) << std::endl;
    std::cout << "Умножение: " << mat_mul::calc(x, y) << std::endl;
    std::cout << "Деление: " << mat_div::calc(x, y) << std::endl;
}
