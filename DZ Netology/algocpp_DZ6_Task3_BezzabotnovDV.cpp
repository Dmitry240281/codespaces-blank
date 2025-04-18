// Задача 3. Упрощённый алгоритм Рабина-Карпа

#include <iostream>
#include <Windows.h>
#include <cmath>

double real_string_hash(std::string str) {
    int p = 53;
    int n = 1000000;
    double hash = 0;
    for (int i = 0; i < str.length(); i++) {
        long long int c = static_cast<int>(str[i]);
        hash += pow(p, i) * c;

    }
    hash = fmod(hash, static_cast<int>(n));
    return hash;
}

int find_substring_light_rabin_karp(std::string string, std::string pattern) {
    int s = string.length();
    int p = pattern.length();
    double hesh_pattern = real_string_hash(pattern);
    
    if (s < p) {
        std::cout << "Такой подстроки определенно нет!" << std::endl;
        return -1;
    }
    int hp1 = static_cast<int>(pattern[0]);
    int h = 0;
    int hs = 0;
    int i = 0;
    while (i < s) {
        hs = static_cast<int>(string[i]);
        if (hp1 == hs) {
            h = i;
            std::string strS = "";
            for (int j = i; j < i+p; j++) {
                strS += string[j];
            }
            double hesh_string = real_string_hash(strS);
            if (hesh_string == hesh_pattern) return h;
            else i++;
        }
        else i++;
    }
    
    return -1;
       
}

int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    std::string str1{ '0' };
    std::string str2{ '0' };
    int rez = -2;

    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> str1;

    do {
        std::cout << "Введите подстроку, которую нужно найти (e - выход): ";
        std::cin >> str2;
        if (str2 == "e") break;
        rez = find_substring_light_rabin_karp(str1, str2);
        if (rez == -1) std::cout << "Подстрока " << str2 << " не найдена" << std::endl;
        else std::cout << "Подстрока " << str2 << " найдена по индексу " << rez << std::endl;
    } while (str2 != "e");


    return EXIT_SUCCESS;
}

