// Задача 1. Частота символов

#include <iostream>
#include <set>
#include <map>
#include <algorithm>

template<typename A, typename B>
std::pair<B, A> flip_pair(const std::pair<A, B>& p)
{
    return std::pair<B, A>(p.second, p.first);
}

template<typename A, typename B>
bool cmp(std::pair<A, B>& a,
    std::pair<A, B>& b)
{
    return a.first < b.first;
}

template<typename A, typename B>
std::multimap<B, A> flip_map(const std::map<A, B>& src)
{
    std::multimap<B, A> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), flip_pair<A, B>);
    //multimap<int, int>::reverse_iterator rit1(range.second);
    return dst;
}

int main()
{
    std::string string = { "Hello World!!" };
    std::multiset<char> ch;
    std::map<char, int> count;
    for (int i = 0; i < string.length(); i++)
        ch.insert(string[i]);
    std::cout << "[IN]: " << string << std::endl;

    //std::cout << "[OUT]: " << std::endl;
    int i = 0;
    for (auto& elem : ch) {
        count[elem] = ch.count(elem);
    }
    std::multimap<int, char> sort_count;
    sort_count = flip_map(count);
    std::cout << "[OUT]: " << std::endl;
    for (auto i = sort_count.rbegin(); i != sort_count.rend(); i++)
        std::cout << i->second << ": " << i->first << std::endl;
    
    return 0;

}

