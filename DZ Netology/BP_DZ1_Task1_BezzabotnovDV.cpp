// Задача 1. Месяцы

#include <iostream>

enum class month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

void error() {
    std::cout << "Неправельный номер!" << std::endl;
}

void exit() {
    std::cout << "До свидания" << std::endl;
}

void fmonth(int m) {
    switch (m) {
    case 0:
        exit();
        break;
    case 1:
        std::cout << "январь" << std::endl;
        break;
    case 2:
        std::cout << "февраль" << std::endl;
        break;
    case 3:
        std::cout << "март" << std::endl;
        break;
    case 4:
        std::cout << "апрель" << std::endl;
        break;
    case 5:
        std::cout << "май" << std::endl;
        break;
    case 6:
        std::cout << "июнь" << std::endl;
        break;
    case 7:
        std::cout << "июль" << std::endl;
        break;
    case 8:
        std::cout << "август" << std::endl;
        break;
    case 9:
        std::cout << "сентябрь" << std::endl;
        break;
    case 10:
        std::cout << "октябрь" << std::endl;
        break;
    case 11:
        std::cout << "ноябрь" << std::endl;
        break;
    case 12:
        std::cout << "декабрь" << std::endl;
        break;
    default: error();
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n;
     do {
        std::cout << "Веведите номер месяца (выход - 0): ";
        std::cin >> n;
        month mon = static_cast<month>(n);
        fmonth(static_cast<int>(mon));
     } while (n != 0);
         
     return EXIT_SUCCESS;
}

