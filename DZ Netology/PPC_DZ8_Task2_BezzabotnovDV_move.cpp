// Задача 2. Большие числа

#include <iostream>
#include <vector>
using std::cout;
using std::endl;

class big_integer {
    char* number;
    long long int x;

public:
    big_integer(const char* num = "") : number(nullptr), x(0) {
        if (num) {
            std::size_t n = std::strlen(num) + 1;
            number = new char[n];
            std::memcpy(number, num, n);
            x = atoll(number);
        }
    }
    ~big_integer() {
        delete[] number;
    }
    big_integer(const big_integer& other) : big_integer(other.number) { x = other.x; }
    big_integer(big_integer&& other) noexcept : number(std::exchange(other.number, nullptr)), x(std::exchange(other.x, 0)) {}
    big_integer& operator=(const big_integer& other) {
        x = other.x;
        return *this = big_integer(other);
    }
    big_integer& operator=(big_integer&& other) noexcept {
        std::swap(number, other.number);
        std::swap(x, other.x);
        return *this;
    }
    long long int operator+(big_integer& other) {
        long long int y = x + other.x;
        return y;
    }

    long long int print() {
        return x;
    }
};

int main()
{
    auto number1 = big_integer("922337203567485");
    auto number2 = big_integer("785241278868568");
    
    cout << "Number 1: " << number1.print() << endl;
    
    cout << "Number 2: " << number2.print() << endl;
    auto result = number1 + number2;
    cout << "Number 1 + Number 2 = " << result << endl;
    auto number3 = big_integer();
    number3 = number2;
    cout << "Number 3: " << number3.print() << endl;
    big_integer number4(std::move(number1));
    cout << "Number 4: " << number4.print() << endl;
    cout << "Number 1: " << number1.print() << endl;

    return 0;
}

