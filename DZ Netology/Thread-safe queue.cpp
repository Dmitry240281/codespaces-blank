// Потокобезопасная очередь

#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <vector>

using namespace std;

mutex m;

class safe_queue {
    queue<function<void()>> Work_queue;
    mutex mtx;
    condition_variable notice;
public:
    
    void push(function<void()> F)
    {
        unique_lock<mutex> lk(mtx);
        Work_queue.push(F);
        notice.notify_all();
    }
    function<void()> front() 
    {
        unique_lock<mutex> lk(mtx);
        function<void()> func = Work_queue.front();
        return func;
        
    }
    void pop()
    {
        unique_lock<mutex> lk(mtx);
        notice.wait(lk, [this]() {return !this->Work_queue.empty(); });
        Work_queue.pop();
        lk.unlock();
    }
    bool empty()
    {
        unique_lock<mutex> lk(mtx);
        return Work_queue.empty();
    }
};

void F1()
{
    cout << "F1\n";
}

void F2()
{
    cout << "F_2\n";
}

bool done = false;

void work(safe_queue &sq)
{
    m.lock();
    cout << "Thread: " << this_thread::get_id() << endl;
    m.unlock();
    while (!done)
    {
        this_thread::sleep_for(100ms);
        function<void()> task;
        if (!sq.empty())
        {
            task = sq.front();
            task();
            sq.pop();
        }
        else
        {
            
            this_thread::yield();
            done = true;
        }

    }
}

int main()
{
    safe_queue SQ;
    for (size_t i = 0; i < 50; i++)
    {
        SQ.push(F1);
        SQ.push(F2);
    }
    int size_thr = thread::hardware_concurrency() - 2;
    cout << size_thr << endl;
    vector<jthread> VT;
    for (size_t i = 0; i < size_thr; i++)
    {
        VT.emplace_back(jthread(work, ref(SQ)));
    }

    return 0;
}

