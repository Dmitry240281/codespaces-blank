// Домашнее задание к занятию «Модель памяти и хранение данных»
// Задание 1

#include <iostream>

int main()
{
	short shP = 2;
	int intP = 50;
	long long_intP = 125973;
	long long L_long_intP = long_intP;
	float floatP = 154.23;
	double doubleP = 1206585575898.5570913783992;
	long double L_doubleP = doubleP;
	bool boo = true;

	std::cout << "short: \t" << &shP << " " << sizeof(shP) << std::endl;
	std::cout << "int: \t" << &intP << " " << sizeof(intP) << std::endl;
	std::cout << "long: \t" << &long_intP << " " << sizeof(long_intP) << std::endl;
	std::cout << "long long: \t" << &L_long_intP << " " << sizeof(L_long_intP)  << std::endl;
	std::cout << "float: \t" << &floatP << " " << sizeof(floatP) << std::endl;
	std::cout << "double: \t" << &doubleP << " " << sizeof(doubleP) << std::endl;
	std::cout << "long double: \t" << &L_doubleP << " " << sizeof(L_doubleP) << std::endl;
	std::cout << "bool: \t" << &boo << " " << sizeof(boo) << std::endl;

	return 0;

}
