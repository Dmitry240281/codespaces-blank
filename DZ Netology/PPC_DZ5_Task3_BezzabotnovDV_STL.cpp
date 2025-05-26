// Задача 3*. Аналог std::vector

#include <iostream>

template<typename T>
class MVector {
    int size;
    int index = 0;
    T* array;
public:
    MVector() : size(10) {
        array = new T[size];
    }

    T at(int ind) {
        if (ind < index)
            return array[ind];
        else 
            throw std::out_of_range("Element out of ranges");
    }

    MVector(const MVector& other) : size(other.size) {
        array = new T[size];
        for (int i = 0; i < size; i++) {
            array[i] = other.array[i];
        }
    }

    MVector& operator=(const MVector& other) {
        if (this != &other) {
            delete[] array;
            size = other.size;
            array = new T[size]; 
            for (int i = 0; i < size; ++i) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

    void push_back(T value) {
        if (index < size) {
            array[index] = value;
            index++;
        }
        else {
            T* temp_array = new T[size];
            for (int i = 0; i < size; i++) {
                temp_array[i] = array[i];
            }
            delete[] array;
            size = size * 2;
            //std::cout << "New Size: " << size << std::endl;
            array = new T[size];
            for (int i = 0; i < size; ++i) {
                array[i] = temp_array[i];
            }
            array[index] = value;
            index++;
            delete[] temp_array;
        }
    }

    int Size() {
        return size;
    }

    int End() {
        return index;
    }

    int capacity() {
        return size - index;
    }

    ~MVector() {
        delete[] array;
    }
};

int main()
{
    try {
    MVector<int> Vec;
    Vec.push_back(1);
    Vec.push_back(6); 
    Vec.push_back(3); 
    Vec.push_back(9); 
    Vec.push_back(5); 
    Vec.push_back(34); 
    Vec.push_back(7); 
    Vec.push_back(18); 
    Vec.push_back(9); 
    Vec.push_back(27); 
    Vec.push_back(11);
    Vec.push_back(12);

    std::cout << "Size: " << Vec.Size() << std::endl;
    std::cout << "My Vector: ";
    for (int m = 0; m < Vec.End(); m++) {
        std::cout << Vec.at(m) << (m == Vec.End() - 1 ? "" : ", ");
    }
    std::cout << std::endl;
    std::cout << "Capacity array: " << Vec.capacity() << std::endl;
    std::cout << std::endl;

    MVector<char> Cvec;
    std::string string = { "Hello World!!" };
    for (int i = 0; i < string.length(); i++)
        Cvec.push_back(string[i]);
    std::cout << "Size string: " << Cvec.Size() << std::endl;
    std::cout << "My Vector string: ";
    for (int c = 0; c < Cvec.End(); c++) {
        std::cout << Cvec.at(c) << (c == Cvec.End() - 1 ? "" : ", ");
    }
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return EXIT_SUCCESS;
}

