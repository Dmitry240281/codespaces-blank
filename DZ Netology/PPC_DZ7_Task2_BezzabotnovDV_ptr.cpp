// Задача 2. Устранение пересечения

#include <iostream>
#include <vector>
#include <memory>

class node
{
public:
    int m_value;
    std::weak_ptr<node> parent;
    node(int value) : m_value{ value } {};
    ~node() { std::cout << "destructor called\n"; }
};

int main()
{
    {
        auto node1 = std::make_shared<node>(1);
        auto node2 = std::make_shared<node>(2);
        node1->parent = node2;
        node2->parent = node1;
        std::cout << node1.get() << " " << (node1->parent).lock().get() << std::endl;
        std::cout << node2.get() << " " << (node2->parent).lock().get() << std::endl;
        std::cout << "Value 1: " << node1->m_value << std::endl;
        std::cout << "Value 2: " << node2->m_value << std::endl;
    }

    return 0;
}