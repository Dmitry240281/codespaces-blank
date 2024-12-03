// Домашнее значение по теме Модель памяти и хранение данных
// Задание 2

#include <iostream>

void swap(int& a, int& b)
{
	int a_ = a;
	a = b;
	b = a_;
}

void swap2(int& a, int& b) // *Вариант 2 без третьей переменной
{
	a = a + b;
	b = a - b;
	a = a - b;
}

int main(int argc, char** argv)
{
	int a = 5, b = 8;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;

	// *Вариант 2 без третьей переменной
	swap2(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;

	return 0;
}

