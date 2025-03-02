// Задача 1. Сравнения в дробях

#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	double DecFrac() {
		double numer = static_cast<double>(numerator_);
		double denom = static_cast<double>(denominator_);
		return numer / denom;
	}
	
	bool operator==(Fraction other) { return DecFrac() == other.DecFrac(); }
	bool operator!=(Fraction other) { return !(*this == other); }
	bool operator>(Fraction other) { return DecFrac() > other.DecFrac(); }
	bool operator<(Fraction other) { return other > *this; }
	bool operator>=(Fraction other) { return !(*this < other); }
	bool operator<=(Fraction other) { return !(*this > other); }

};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	//std::cout << f1.DecFrac() << std::endl;
	//std::cout << f2.DecFrac() << std::endl;

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n'; // f1 not == f2
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n'; // f1 != f2
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';    // f1 not < f2
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';    // f1 > f2
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n'; // f1 not <= f2
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n'; // f1 >= f2
	return 0;
}

