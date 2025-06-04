// Задача 1. Перемещение объектов

#include <iostream>
#include <vector>
using std::cout;
using std::endl;


template<typename T>
void move_vectors(std::vector<T>& vec1, std::vector<T>& vec2) {
    vec2 = std::move(vec1);
}

int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    cout << "Vector One: ";
    for (auto i : one) {
        cout << i << " ";
    }
    cout << endl;
    std::vector <std::string> two;

    move_vectors(one, two); // Перемещаем vector 1 в vector 2

    cout << "Vector Two: ";
    for (auto i : two) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Vector One_: ";
    for (auto i : one) {
        cout << i << " ";
    }

    return 0;
}

