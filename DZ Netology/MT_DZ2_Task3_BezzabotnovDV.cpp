// Задание 3
// Защищённый обмен данными

#include <iostream>
#include <mutex>
#include <thread>

class Data
{
private:
    int value;
    std::mutex mtx;

public:
    Data(int val = 0) : value(val) {}

    int get_value() const {
        return value;
    }

    void set_value(int val) {
        value = val;
    }

    void lock() {
        mtx.lock();
    }

    void unlock() {
        mtx.unlock();
    }

    std::mutex& get_mutex() {
        return mtx;
    }
};

// Вариант 1: std::lock
void swap_lock(Data& a, Data& b) {
    std::lock(a.get_mutex(), b.get_mutex());
    std::lock_guard<std::mutex> lock_a(a.get_mutex(), std::adopt_lock);
    std::lock_guard<std::mutex> lock_b(b.get_mutex(), std::adopt_lock);

    int temp = a.get_value();
    a.set_value(b.get_value());
    b.set_value(temp);
}

// Вариант 2: std::scoped_lock (C++17)
void swap_scoped_lock(Data& a, Data& b) {
    std::scoped_lock lock(a.get_mutex(), b.get_mutex());

    int temp = a.get_value();
    a.set_value(b.get_value());
    b.set_value(temp);
}

// Вариант 3: std::unique_lock
void swap_unique_lock(Data& a, Data& b) {
    std::unique_lock<std::mutex> lock_a(a.get_mutex(), std::defer_lock);
    std::unique_lock<std::mutex> lock_b(b.get_mutex(), std::defer_lock);
    std::lock(lock_a, lock_b);

    int temp = a.get_value();
    a.set_value(b.get_value());
    b.set_value(temp);
}

int main()
{
    setlocale(LC_ALL, "rus");
    Data d1(10);
    Data d2(20);

    std::cout << "До обмена: d1 = " << d1.get_value() << ", d2 = " << d2.get_value() << std::endl;

    swap_lock(d1, d2);
    std::cout << "После обмена с lock: d1 = " << d1.get_value() << ", d2 = " << d2.get_value() << std::endl;

    swap_scoped_lock(d1, d2);
    std::cout << "После обмена с scoped_lock: d1 = " << d1.get_value() << ", d2 = " << d2.get_value() << std::endl;

    swap_unique_lock(d1, d2);
    std::cout << "После обмена с unique_lock: d1 = " << d1.get_value() << ", d2 = " << d2.get_value() << std::endl;

    return 0;
}