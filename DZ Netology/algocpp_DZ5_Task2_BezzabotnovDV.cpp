// Задача 2. «Путешествие» по пирамиде

#include <iostream>
#include <string>
#include <cmath>

class heap {
    int size = 0;
    int* arr = new int[size];
    int index = 0;
public:
    heap(int* arr, int size, int index) {
        this->arr = arr;
        this->size = size;
        this->index = index;
    }

    int root() { return arr[0]; };

    int from_index(int index) {
        return arr[index];
    }

    int left_index(int parant_index) {
        return 2 * parant_index + 1;
    }

    int right_index(int parant_index) {
        return 2 * parant_index + 2;
    }

    int parant_index(int child_index) {
        return (child_index - 1) / 2;
    }

    std::string print_pyramid(int i)
    {
        
        if (i == 0) {
            return std::to_string(i) + " root " + std::to_string(root());
            //k++;
        }
        else if (i % 2 == 0) return std::to_string(i) + " right( " + std::to_string(arr[parant_index(i)]) + ") " + std::to_string(arr[right_index(parant_index(i))]);
        else return std::to_string(i) + " left(" + std::to_string(arr[parant_index(i)]) + ") " + std::to_string(arr[left_index(parant_index(i))]);
        //if (i > k * k) k++;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    int index = 0;
    char control = '0';
    int array3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    
    int size3 = sizeof(array3) / sizeof(array3[0]);
    
    std::cout << "Исходный массив 3: ";
    for (int i = 0; i < size3; i++)
        std::cout << array3[i] << ", ";
    std::cout << std::endl;
    std::cout << "Пирамида 3: " << std::endl;
    
    heap H3(array3, size3, index);
    for (int i = 0; i < size3; i++) {
        
        std::cout << H3.print_pyramid(i) << std::endl;
    }
        
    while (control != 'e') {
        std::cout << "Вы находитесь здесь: " << H3.print_pyramid(index) << std::endl;
        std::cout << "Введите команду (u - родитель, r - вправо, l - влево, e - выход): ";
        std::cin >> control;
        if (control == 'u') {
            int old_index = index;
            index = (index - 1) / 2;
            if (index < 0 || old_index == 0) {
                std::cout << "Ошибка! Отсутствует родитель" << std::endl;
                index = old_index;
            }
        }
        else if (control == 'r') {
            int old_index = index;
            index = 2 * index + 2;
            if (index >= size3) {
                std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
                index = old_index;
            }
        }
        else if (control == 'l') {
            int old_index = index;
            index = 2 * index + 1;
            if (index >= size3) {
                std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
                index = old_index;
            }
        }
        else if (control == 'e') {}
        else std::cout << "Ошибка ввода команды!" << std::endl;
    }
    std::cout << "ДОСВИДАНИЕ!" << std::endl;

    return EXIT_SUCCESS;
}