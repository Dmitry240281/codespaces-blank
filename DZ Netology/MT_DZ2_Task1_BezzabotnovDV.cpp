//Задание 1
//чередь клиентов

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
using namespace std;

void first_window(atomic<int> start)
{
    int end = start;
    cout << "Первое окно: начало работать!" << endl;
    for (int i = 0; i < end; ++i)
    {
        start.exchange (++start, memory_order_acquire);
        //cout << start.load() << ' ';
        this_thread::sleep_for(100ms);
    }
    cout << endl;
    cout << "Первое окно: закончило работать!" << endl;
}
void second_window(atomic<int> start)
{
    cout << "Второе окно: начало работать!" << endl;
    do
    {
        start.exchange(--start, memory_order_acquire);
        //cout << start.load() << " ";
        this_thread::sleep_for(300ms);
    } while (start > 0);
    cout << endl;
    cout << "Второе окно: закончило работать!" << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    atomic<int> queue;
    queue.store(10);

    auto start = chrono::system_clock::now();
    time_t now_t = chrono::system_clock::to_time_t(start);
    cout << "Время начала работы: ";
    cout << ((now_t / 3600 + 3) % 24) << " ч. " << (now_t / 60 % 60) << " м. " << (now_t % 6) << " c." << endl;

    thread window1(first_window, queue.load());
    thread window2(second_window, queue.load());
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