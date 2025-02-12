// Задача 1. Адреса

#include <iostream>
#include<fstream>
#include<string>

class Address {
    std::string city;
    std::string street;
    int house_num;
    int flat_num;
public:
    Address(){}
    Address(std::string city, std::string street, int house_num, int apartment_num) {
        this->city = city;
        this->street = street;
        this->house_num = house_num;
        this->flat_num = apartment_num;
    }
    std::string get_output_address() {
        std::string address_print;
        address_print = city + ", " + street + ", " + std::to_string(house_num) + ", " + std::to_string(flat_num);
        return address_print;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    std::string mcity, mstreet;
    int mhouse, mflat;
    int size;
    std::ifstream fin("in.txt");
    if (!fin.is_open()) {
        std::cout << "Файл не найден. Проверьте наличие и название файла" << std::endl;
        return 0;
    }
    fin >> size;
    Address* address = new Address[size];

    for (int i = 0; i < size; i++) {
        fin >> mcity >> mstreet >> mhouse >> mflat;
        address[i] = Address(mcity, mstreet, mhouse, mflat);
    }
    fin.close();

    std::ofstream fout{ "out.txt"};
    if (!fout.is_open()) {
        std::cout << "Файл не найден. Проверьте наличие и название файла" << std::endl;
        return 1;
    }
    fout << size << std::endl;
        for (int i = size - 1; i >= 0; i--) {
            fout << address[i].get_output_address() << std::endl;
        }
    fout.close();

        delete[] address;
}


