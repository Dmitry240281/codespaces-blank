//Задание 1
//чередь клиентов

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void first_window(int start)
{
    int end = start;
    cout << "Первое окно: начало работать!\n";
    for (int i = 0; i < end; ++i)
    {
        ++start;
        this_thread::sleep_for(2s);
    }
    cout << "Первое окно: закончило работать!" << endl;
}
void second_window(int start)
{
    cout << "Второе окно: начало работать!\n";
    do
    {
        --start;
        this_thread::sleep_for(3s);
    } while (start > 0);
    cout << "Второе окно: закончило работать!" << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int queue = 10;
    auto start = chrono::system_clock::now();
    time_t now_t = chrono::system_clock::to_time_t(start);
    cout << "Время начала работы: ";
    cout << ((now_t / 3600 + 3) % 24) << " ч. " << (now_t / 60 % 60) << " м. " << (now_t % 6) << " c." << endl;
    thread window1(first_window, queue);
    thread window2(second_window, queue);
    window1.join();
    auto end1 = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds1 = end1 - start;
    cout << "Время работы 1 окна: " << elapsed_seconds1.count() << "s" << endl;
    window2.join();
    auto end2 = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds2 = end2 - start;
    cout << "Время работы 2 окна: " << elapsed_seconds2.count() << "s" << endl;

    return 0;
}
