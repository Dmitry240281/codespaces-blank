// Задача 3. Счётчик чисел
/*
В этом задании вам нужно реализовать функтор, который подсчитывает сумму и 
количество чисел, делящихся на 3.
Должны быть реализованы 2 функции:
get_sum()
get_count()
*/

#include <iostream>
#include <vector>

class Functor {
    int sum = 0;
    int counters = 0;
public:
    Functor() = default;
    void operator()(int i) {
        if (i % 3 == 0) {
            sum = sum + i;
            counters++;
        }
    }
    int get_sum() {
        return sum;
    }
    int get_count() {
        return counters;
    }
};

int main()
{
    std::vector<int> v{ 4, 1, 3, 6, 25, 54 };
    Functor Fu;
    std::cout << "[IN]: ";
    for (const auto i : v) {
        Fu(i);
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "[OUT]: get_sum() = " << Fu.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << Fu.get_count() << std::endl;

    return 0;
}

