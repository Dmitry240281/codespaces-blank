// MT_DZ3_Task1_BezzabotnovDV_async.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>
#include <future>
#include <thread>
#include <vector>

using namespace std;

promise<vector<int>::iterator> find_min_value(vector<int>& v, vector<int>::iterator it) {
    promise<vector<int>::iterator> promise;
    auto min_it = it;
    for (auto it2 = it + 1; it2 < v.end(); ++it2)
    {
        if ((*it2) < (*min_it)) {
            min_it = it2;
        }
    }
    promise.set_value(min_it);
    return promise;
}

int main()
{
    vector<int> V{ 1,35,64,23,3,78,5,89,34,56,178,27,95,4,95,3 };
    
    auto start = chrono::system_clock::now();
    for (auto it = V.begin(); it < V.end() - 1; ++it)
    {
        std::promise<vector<int>::iterator> Promise = find_min_value(V, it);
        std::future<vector<int>::iterator> Future = Promise.get_future();
        
        auto minit = Future.get();
        swap(*it, *minit);
    }
    auto end = chrono::system_clock::now();
    chrono::duration<double, milli> time = end - start;
    cout << "Time = " << time.count() << " ms" << endl;

    cout << "Vector: " << endl;
    for (auto i : V) cout << i << ' ';
    cout << endl;

    return 0;
}

