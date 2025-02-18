// Задача 2. Фигуры. Стороны и углы

#include <iostream>

class Figure {
protected:
    std::string name;
public:
    void get_print(std::string name) const {
        std::cout << name << ": " << std::endl;
    }
};

class Quadrate : public Figure {
protected:
    double a{}, b{}, c{}, d{}; // Стороны
    double A{}, B{}, C{}, D{}; // Углы
public:
    Quadrate(double a=10, double b=20, double c=30, double d=40, double A=50, double B=60, double C=70, double D=80) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        name = "Четырехугольник";
    }
    void print_info() const {
        get_print(name);
        std::cout << "Стороны: " << "a=" << a << ' ' << "b=" << b << ' ' << "c=" << c << ' ' << "d=" << d << std::endl;
        std::cout << "Углы: " << "A=" << A << ' ' << "B=" << B << ' ' << "C=" << C << ' ' << "D=" << D << std::endl;
        std::cout << std::endl;
    }
};
// Прямоугольник (стороны попарно равны, углы = 90)
class Quadrate_Rectangle : public Quadrate {
public:
    Quadrate_Rectangle(double a=10, double b=20, double A=90) : Quadrate(a, b, a, b, A, A, A, A) {
        name = "Прямоугольник";        
    }
    void print() const {
        print_info();
    }
};

// Крабрат - все стороны равны, все углы по 90 градусов
class Quadrate_Square : public Quadrate {
public:
    Quadrate_Square(double a = 20, double A = 90) : Quadrate(a, a, a, a, A, A, A, A) {
        name = "Квадрат";
    }
    void print() const {
        print_info();
    }
};

// Параллелограмм - стороны папарно равны, углы не равны 90 градусов но попарно равны
class Quadrate_Parallelogram : public Quadrate {
public:
    Quadrate_Parallelogram(double a = 20, double b = 30, double A = 30, double B = 40) : Quadrate(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм";
    }
    void print() const {
        print_info();
    }
};

//ромб (все стороны равны, углы A, C и B, D попарно равны).
class Quadrate_Rhombus : public Quadrate {
public:
    Quadrate_Rhombus(double a=30, double A=30, double B=40) : Quadrate(a, a, a, a, A, B, A, B) {
        name = "Ромб";
    }
    void print() const {
        print_info();
    }
};

//Треугольник
class Triangle : public Figure {
protected:
    double a{}, b{}, c{}; // Стороны
    double A{}, B{}, C{}; // Углы
public:
    Triangle(double a = 10, double b = 20, double c = 30, double A = 50, double B = 60, double C = 70) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        name = "Треугольник";
    }
    void print_info() const {
        get_print(name);
        std::cout << "Стороны: " << "a=" << a << ' ' << "b=" << b << ' ' << "c=" << c << std::endl;
        std::cout << "Углы: " << "A=" << A << ' ' << "B=" << B << ' ' << "C=" << C << std::endl;
        std::cout << std::endl;
    }
};

// Прямоугольный треугольник - треугольник у которого один угол = 90
class Triangle_Right_triangle : public Triangle {
public:
    Triangle_Right_triangle(double a=10, double b=20, double c = 30, double A = 50, double B = 60, double C = 90) : Triangle(a, b, c, A, B, C) {
        name = "Прямоугольный треугольник";
    }
    void print() const {
        print_info();
    }
};

// Равнобедренный треугольник - треугольник у которого две стороны и два угла равны
class Triangle_Isosceles_triangle : public Triangle {
public:
    Triangle_Isosceles_triangle(double a = 10, double b = 20, double A = 50, double B = 60) : Triangle(a, b, a, A, B, A) {
        name = "Равнобедренный треугольник";
    }
    void print() const {
        print_info();
    }
};

// Равносторонний треугольник - треугольник у которого все стороны и углы равны
class Triangle_Equilateral_triangle : public Triangle {
public:
    Triangle_Equilateral_triangle(double a = 30, double A = 60) : Triangle(a, a, a, A, A, A) {
        name = "Равносторонний треугольник";
    }
    void print() const {
        print_info();
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    Triangle Tr;
    Tr.print_info();
    Triangle_Right_triangle Rt;
    Rt.print();
    Triangle_Isosceles_triangle It;
    It.print();
    Triangle_Equilateral_triangle Et;
    Et.print();
    Quadrate Q;
    Q.print_info();
    Quadrate_Rectangle Re;
    Re.print();
    Quadrate_Square Sq;
    Sq.print();
    Quadrate_Parallelogram Pa;
    Pa.print();
    Quadrate_Rhombus R;
    R.print();


    return EXIT_SUCCESS;
}