// Задача 2. Остальные операции с дробями

#include <iostream>
#include <string>
#include <numeric>


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
	//double DecFrac() {
	//	double numer = static_cast<double>(numerator_);
	//	double denom = static_cast<double>(denominator_);
	//	return numer / denom;
	//}
	Fraction operator+(Fraction other) {
		int new_numerator = (numerator_ * other.denominator_) + (other.numerator_ * denominator_);
		int new_denominator = (denominator_ * other.denominator_);
		int gcd = std::gcd(new_numerator, new_denominator); // Вычисляем наибольший общий знаменатель
		//std::cout << numerator_ << "/" << denominator_ << " + " << other.numerator_ << "/" << other.denominator_ << " = " << new_numerator / gcd << "/" << new_denominator / gcd << std::endl;
		return Fraction(new_numerator / gcd, new_denominator / gcd);
	}
	Fraction operator-(Fraction other) {
		int new_numerator = (numerator_ * other.denominator_) - (other.numerator_ * denominator_);
		int new_denominator = (denominator_ * other.denominator_);
		int gcd = std::gcd(new_numerator, new_denominator); // Вычисляем наибольший общий знаменатель
		//std::cout << numerator_ << "/" << denominator_ << " - " << other.numerator_ << "/" << other.denominator_ << " = " << new_numerator / gcd << "/" << new_denominator / gcd << std::endl;
		return Fraction(new_numerator / gcd, new_denominator / gcd);
	}
	Fraction operator*(Fraction other) {
		int new_numerator = numerator_ * other.numerator_;
		int new_denominator = denominator_ * other.denominator_;
		int gcd = std::gcd(new_numerator, new_denominator); // Вычисляем наибольший общий знаменатель
		//std::cout << numerator_ << "/" << denominator_ << " * " << other.numerator_ << "/" << other.denominator_ << " = " << new_numerator / gcd << "/" << new_denominator / gcd << std::endl;
		return Fraction(new_numerator/gcd, new_denominator/gcd);
	}
	Fraction operator/(Fraction other) {
		int new_numerator = numerator_ * other.denominator_;
		int new_denominator = denominator_ * other.numerator_;
		int gcd = std::gcd(new_numerator, new_denominator); // Вычисляем наибольший общий знаменатель
		//std::cout << numerator_ << "/" << denominator_ << " / " << other.numerator_ << "/" << other.denominator_ << " = " << new_numerator / gcd << "/" << new_denominator / gcd << std::endl;
		return Fraction(new_numerator / gcd, new_denominator / gcd);
	}
	// инкремент
	Fraction operator++() { // инкремент префиксный
		int new_numerator = numerator_+ denominator_;
		int new_denominator = denominator_;
		int gcd = std::gcd(new_numerator, new_denominator);
		//std::cout << "++" << new_numerator / gcd << "/" << new_denominator / gcd;
		return Fraction(new_numerator / gcd, new_denominator / gcd); 
	}
	Fraction operator++(int)								// инкремент постфиксный
	{
		Fraction temp = *this;
		++(*this);
		return temp;
	}
	Fraction operator--() { // Декременент префиксный
		int new_numerator = numerator_ - denominator_;
		int new_denominator = denominator_;
		int gcd = std::gcd(new_numerator, new_denominator);
		//std::cout << "++" << new_numerator / gcd << "/" << new_denominator / gcd;
		return Fraction(new_numerator / gcd, new_denominator / gcd);
	}
	Fraction operator--(int)								// инкремент постфиксный
	{
		Fraction temp = *this;
		--(*this);
		return temp;
	}
	std::string Print() {
		//std::cout << numerator_ << "/" << denominator_;
		return std::to_string(numerator_) + "/" + std::to_string(denominator_);
	}
};

std::string Print_fra(int num, int den) {
	return std::to_string(num) + "/" + std::to_string(den);
	
}

int main()
{
	setlocale(LC_ALL, "rus");
	int num1, num2, den1, den2;
	std::cout << "Введите числитель дроби 1: "; std::cin >> num1;
	std::cout << "Введите знаменатель дроби 1: "; std::cin >> den1;
	std::cout << "Введите числитель дроби 2: "; std::cin >> num2;
	std::cout << "Введите знаменатель дроби 2: "; std::cin >> den2;
	Fraction f1(num1, den1);
	Fraction f2(num2, den2);

	Fraction sum = f1 + f2;
	std::cout << Print_fra(num1, den1) << " + " << Print_fra(num2, den2) << " = " << sum.Print() << std::endl;
	//Print_fra(num1, num2, den1, den2, sum, "+");

	Fraction sub = f1 - f2;
	std::cout << Print_fra(num1, den1) << " - " << Print_fra(num2, den2) << " = " << sub.Print() << std::endl;
	//Print_fra(num1, num2, den1, den2, sub, "-");

	Fraction mult = f1 * f2;
	std::cout << Print_fra(num1, den1) << " * " << Print_fra(num2, den2) << " = " << mult.Print() << std::endl;
	//Print_fra(num1, num2, den1, den2, mult, "*");

	Fraction del = f1 / f2;
	std::cout << Print_fra(num1, den1) << " / " << Print_fra(num2, den2) << " = " << del.Print() << std::endl;
	//Print_fra(num1, num2, den1, den2, del, "/");

	Fraction mult2 = ++f1 * f2;
	std::cout << "++" << Print_fra(num1, den1) << " * " << Print_fra(num2, den2) << " = " << mult2.Print() << std::endl;
	Fraction inc = ++f1;
	std::cout << "Значение дроби 1 = " << inc.Print() << std::endl;
	//std::cout << "++" << inc.Print() << std::endl;

	Fraction mult3 = (inc--)*f2;
	std::cout << inc.Print() << "--"  << " * " << Print_fra(num2, den2) << " = " << mult3.Print() << std::endl;
	Fraction dec = f1--;
	std::cout << "Значение дроби 1 = " << dec.Print() << std::endl;
	//std::cout << "++" << inc.Print() << std::endl;



	return EXIT_SUCCESS;
}