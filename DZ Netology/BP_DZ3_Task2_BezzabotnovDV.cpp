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
    void set_city(Address& city, Address& city_new) {
        std::string temp_city, temp_street;
        int temp_house_num, temp_flat_num;
        temp_city = city_new.city;
        temp_street = city_new.street;
        temp_house_num = city_new.house_num;
        temp_flat_num = city_new.flat_num;

        city_new.city = this->city;
        city_new.street = this->street;
        city_new.house_num = this->house_num;
        city_new.flat_num = this->flat_num;

        this->city = temp_city;
        this->street = temp_street;
        this->house_num = temp_house_num;
        this->flat_num = temp_flat_num;
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
                address[j].set_city(address[j], address[j + 1]);
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