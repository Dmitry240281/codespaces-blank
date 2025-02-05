// Задача 3. Вывод структуры

#include <iostream>
#include <Windows.h>

struct adress {
    std::string city;
    std::string street;
    int house;
    int apartment;
    int zip_code;
};

void print_adr(adress* pa, int s) {
    for (int i = 0; i < s; i++) {
        std::cout << "Город: " << pa[i].city << std::endl;
        std::cout << "Улица: " << pa[i].street << std::endl;
        std::cout << "Номер дома: " << pa[i].house << std::endl;
        std::cout << "Номер квартиры: " << pa[i].apartment << std::endl;
        std::cout << "Индекс: " << pa[i].zip_code << std::endl;
        std::cout << std::endl;
    }
}

int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    
    int size(2);
    adress* adr = new adress[size];

    adr[0].city = "Москва";
    adr[0].street = "Арбат";
    adr[0].house = 12;
    adr[0].apartment = 8;
    adr[0].zip_code = 123456;

    adr[1].city = "Ижевск";
    adr[1].street = "Пушкина";
    adr[1].house = 59;
    adr[1].apartment = 143;
    adr[1].zip_code = 953769;

    print_adr(adr, size);
    delete[] adr;

    // Ввод адреса с консоли
    int sizen(20);
    adress* adr_arr = new adress[sizen];
    int s = 0;
    do {
        
        std::string exit = "да";
        std::cout << "Введите свой адрес: " << std::endl;
        std::cout << "Город: ";
        std::cin >> adr_arr[s].city;
        std::cout << "Улица: ";
        std::cin >> adr_arr[s].street;
        std::cout << "Номер дома: ";
        std::cin >> adr_arr[s].house;
        std::cout << "Номер квартиры: ";
        std::cin >> adr_arr[s].apartment;
        std::cout << "Индекс: ";
        std::cin >> adr_arr[s].zip_code;

        std::cout << "Хотите ввести еще адрес (да/нет): ";
        std::cin >> exit;
        if (exit == "да") {
            s++;
        }
        else 
            { std::cout << "Спасибо!" << std::endl;
            sizen = s + 1;
            break;
            }
    } while (true);
    print_adr(adr_arr, sizen);
    delete[] adr_arr;

    return EXIT_SUCCESS;
}

