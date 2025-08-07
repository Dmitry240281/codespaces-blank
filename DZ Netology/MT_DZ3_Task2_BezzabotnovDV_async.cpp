// Задание 2
// parallel_for_each

#include <iostream>
#include <chrono>
#include <future>
#include <vector>

using namespace std;

template<typename Iterator, typename T>
void parallel_for_each(Iterator first, Iterator last, T&& func, size_t min_size = 1000)
{
    const size_t size = std::distance(first, last);

    if (size < min_size)
    {
        std::for_each(first, last, forward<T>(func));
        return;
    }
    else {
        Iterator middle = first;
        std::advance(middle, size / 2);

        auto future = std::async(launch::async,
            [first, middle, &func, min_size]()
            {
                parallel_for_each(first, middle, forward<T>(func), min_size);
            });

        parallel_for_each(middle, last, forward<T>(func), min_size);
        future.get();
    }
}

int main()
{
    vector<int> V(1'000'000, 2);

    auto process_func = [](int& n) { n += 2; }; // Обрабатывающая функция

    auto start = chrono::system_clock::now();
    for_each(V.begin(), V.end(), process_func);
    auto end = chrono::system_clock::now();
    chrono::duration<double, milli> time = end - start;
    cout << "Time for_each = " << time.count() << " ms" << endl;

    auto start1 = chrono::system_clock::now();
    parallel_for_each(V.begin(), V.end(), process_func);
    cout << endl;
    auto end1 = chrono::system_clock::now();
    chrono::duration<double, milli> time1 = end1 - start1;
    cout << "Time parallel_for_each = " << time1.count() << " ms" << endl;

    return 0;
}

