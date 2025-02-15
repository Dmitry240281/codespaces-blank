// Задача 2. Сортируем адреса

#include <iostream>
#include<fstream>
#include<string>

class Address {
    std::string city;
    std::string street;
    int house_num;
    int flat_num;
public:
    Address() {}
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
    std::string get_city() {
        return city;
    }
    std::string get_street() {
        return street;
    }
    int get_house_num() {
        return house_num;
    }
    int get_flat_num() {
        return flat_num;
    }
    void set_city(std::string city) {
        this->city = city;
    }
    void set_street(std::string street) {
        this->street = street;
    }
    void set_house_num(int house_num) {
        this->house_num = house_num;
    }
    void set_flat_num(int flat_num) {
        this->flat_num = flat_num;
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

    // Пузырьковый метод
    bool swapped = false;

    do {
        swapped = false;
        for (int j = 0; j < size-1; j++) {
            std::string c1 = address[j].get_city();
            std::string c2 = address[j+1].get_city();
            if (c1 > c2) {
                Address temp;
                temp.set_city(address[j + 1].get_city());
                temp.set_street(address[j + 1].get_street());
                temp.set_house_num(address[j + 1].get_house_num());
                temp.set_flat_num(address[j + 1].get_flat_num());

                address[j + 1].set_city(address[j].get_city());
                address[j + 1].set_street(address[j].get_street());
                address[j + 1].set_house_num(address[j].get_house_num());
                address[j + 1].set_flat_num(address[j].get_flat_num());

                address[j].set_city(temp.get_city());
                address[j].set_street(temp.get_street());
                address[j].set_house_num(temp.get_house_num());
                address[j].set_flat_num(temp.get_flat_num());

                swapped = true;
            }
        }
    } while (swapped);

    std::ofstream fout{ "out.txt"};
    if (!fout.is_open()) {
        std::cout << "Файл не найден. Проверьте наличие и название файла" << std::endl;
        return 1;
    }
    fout << size << std::endl;
    for (int i = 0; i < size; i++) {
        fout << address[i].get_output_address() << std::endl;
    }
    fout.close();

    delete[] address;

    return EXIT_SUCCESS;
}