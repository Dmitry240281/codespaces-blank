// Задача 1. Простое исключение

#include <iostream>
#include <Windows.h>

class ForbiddenWordLength : public std::exception {
public:
    const char* what() const override { return "Вы ввели слово запретной длины! До свидания"; }
};


int function(std::string str, int forbidden_length) {
    int s = str.length();
    if (s != forbidden_length) return s;
    else {
        throw ForbiddenWordLength();
        return 0;
    }
}

int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
        int m_fl, m_leng;
        std::string m_str;
        std::cout << "Введите запретную длину: ";
        std::cin >> m_fl;
 try
        {
     do {
        std::cout << "Введите слово: ";
        std::cin >> m_str;

       
            m_leng = function(m_str, m_fl);
            std::cout << "Длина слова \"" << m_str << "\" равна " << m_leng << std::endl;
        
     } while (m_leng != 0);
}

 catch (const ForbiddenWordLength& ex) {
     std::cout << ex.what() << std::endl;
 }
 catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

    return EXIT_SUCCESS;
}

