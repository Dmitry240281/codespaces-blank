// Задача 2. Большие числа

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;

class big_integer {
    std::vector<int> number;
public:
    big_integer(std::string num = "") {
        std::transform(num.begin(), num.end(), back_inserter(number), [](char c) { return c - '0'; });
    }
    ~big_integer() {}
    big_integer(const big_integer& other) { 
        this->number = other.number;
    }
    big_integer(big_integer&& other) noexcept {
        this->number = std::move(other.number);
        
    }
    big_integer& operator=(const big_integer& other) {
        this->number = other.number;
        return *this;
    }
    big_integer& operator=(big_integer&& other) noexcept {
        std::swap(number, other.number);
        return *this;
    }
    std::string operator+(big_integer& other) { // Сложение в столбик
        std::string summav;
        std::vector<int> vec1 = this->number;
        std::vector<int> vec2 = other.number;
        int transfer = 0;
        auto it1 = vec1.begin();
        auto it2 = vec2.begin();
        int index1 = vec1.size() - 1;
        int index2 = vec2.size() - 1;
        while (index1 >= 0 || index2 >=0) {
            int a = vec1.at(index1);
            int b = vec2.at(index2);
            int itsn = 0;
            int sum = a + b + transfer;
            if (sum > 9) {
                itsn = sum - 10;
                transfer = 1;
            }
            else {
                itsn = sum;
                transfer = 0;
            }
            if (transfer > 0 && index1 == 0 || vec1.size() < vec2.size()) {
                vec1.insert(vec1.begin(), 0);
                index1++;
            }
            if (transfer > 0 && index2 == 0 || vec1.size() > vec2.size()) {
                vec2.insert(vec2.begin(), 0);
                index2++;
            }
            std::string nstr = std::to_string(itsn);
            summav = nstr + summav;
            index1--;
            index2--;
        }
        return summav;
    }
    big_integer operator*(int num) { // Умножение на число
        std::string Mult;
        std::vector<int> vec = this->number;
        int index = vec.size() - 1;
        //int transfer = 0;
        big_integer Summ("0");
        //int summ = 0;
        int indsu = 1;
        while (index >= 0) {
            int a = vec.at(index);
            int mult = num * a * indsu;
            big_integer Mult(std::to_string(mult));
            Summ = Summ + Mult;
            //summ = summ + (mult * indsu);
            indsu = indsu *10;
            index--;
            
        }
        //Mult = std::to_string(summ);
        return Summ;

    }
    void print() {
        for (auto i : number) {
            cout << i;
        }
        cout << endl;
    }
};

int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    
    cout << "Number 1: ";
    number1.print();
    
    cout << "Number 2: ";
    number2.print();

    auto result = number1 + number2;
    cout << "Number 1 + Number 2 = " << result << endl;
    int num = 32;
    auto mult = number1 * num;
    cout << "Number 1 * " << num << " = ";
    mult.print();

    auto number3 = big_integer();
    number3 = number2;
    cout << "Number 3: ";
    number3.print();
    big_integer number4(std::move(number1));
    cout << "Number 4: ";
    number4.print();
    cout << "Number 1: ";
    number1.print();

    return 0;
}

