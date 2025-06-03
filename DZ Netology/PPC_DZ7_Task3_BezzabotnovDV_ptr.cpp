// Задача 3*. std::unique_ptr своими руками

#include <iostream>

class Test {
    int __value;
public:
    Test(int value) : __value(value) {}
    int get_value() {
        return __value;
    }
};

template<typename T>
class MyUniquePtr {
    T* pointer = nullptr;
public:
    explicit MyUniquePtr(T* ptr) : pointer(ptr) {}
    void operator=(MyUniquePtr& other) = delete;
    MyUniquePtr(const MyUniquePtr& other) = delete;
    ~MyUniquePtr() {
        delete pointer;
        std::cout << "Delete My Unique Ptr!" << std::endl;
    }
    T& operator*() {
        if (pointer == nullptr) {
            std::cout << "Pointer is null." << std::endl;
        }
        else {
            return *pointer;
            std::cout << "Pointer is not null." << std::endl;
        }
        
    }
    T* operator->() {
        return pointer;
    }
    T* release() {
        pointer = nullptr;
        pointer = new T;
        return pointer;
    }
};

int main()
{
    MyUniquePtr<int> ptr1(new int);
    *ptr1 = 25;
    std::cout << "New ptr: " << * ptr1 << std::endl;
    int *p = ptr1.release();
    *p = 35;
    std::cout << "After release ptr: " << *ptr1 << std::endl;

    MyUniquePtr<Test> ptr2(new Test(400));
    std::cout << "Test ptr: " << ptr2->get_value() << std::endl;
    int k = 1;
    MyUniquePtr<int> arr(new int[10]);
    for (size_t i = 0; i < 10; i++) {
        *arr = k++;
    }
    std::cout << "Array: ";
    for (size_t j = 0; j < 10; j++)
    {
        std::cout << *arr << " ";
    }
    std::cout << std::endl;

    return 0;
}

