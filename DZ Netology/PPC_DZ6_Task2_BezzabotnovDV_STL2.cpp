// Задача 2. Печать контейнера

#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <map>

template <typename T>
void print_container(std::set<T> set) {
    std::cout << "Set container: ";
    for (auto s : set)
        std::cout << s << " ";
    std::cout << std::endl;
}
template <typename T>
void print_container(std::list<T> list) {
    std::cout << "List container: ";
    for (auto l : list)
        std::cout << l << " ";
    std::cout << std::endl;
}
template <typename T>
void print_container(std::vector<T> vec) {
    std::cout << "Vector container: ";
    for (auto v : vec)
        std::cout << v << " ";
    std::cout << std::endl;
}
template <typename A, typename B>
void print_container(std::map<A, B> map) {
    std::cout << "Map container: " << std::endl;
    for (auto m : map)
        std::cout <<"[ " << m.first << ", " << m.second << " ]" << std::endl;
    std::cout << std::endl;
}

int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set); // four one three two. Set - сортирует по возрастанию

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list); // one, two, three, four

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector); // one, two, three, four

    std::map<int, std::string> test_map = { {1,"one"}, {2,"two"},{3,"three"},{4,"four"} };
    print_container(test_map);

    return 0;
}

