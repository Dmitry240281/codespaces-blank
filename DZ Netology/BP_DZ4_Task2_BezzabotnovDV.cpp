// Задача 2. Фигуры. Стороны и углы

#include <iostream>

class Figure {
protected:
    std::string name;
public:
    void F_print(std::string name) {
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
    void print_info() {
        F_print(name);
        std::cout << "Стороны: " << "a=" << a << ' ' << "b=" << b << ' ' << "c=" << c << ' ' << "d=" << d << std::endl;
        std::cout << "Углы: " << "A=" << A << ' ' << "B=" << B << ' ' << "C=" << C << ' ' << "D=" << D << std::endl;
    }
};
// Прямоугольник (стороны попарно равны, углы = 90)
class rectangle : public Quadrate {
public:
    rectangle(double a=10, double b=20, double A=90) : Quadrate(a, b, a, b, A, A, A, A) {
        name = "Прямоугольник";        
    }
    void print() {
        print_info();
    }
};

// Крабрат - все стороны равны, все углы по 90 градусов
class square : public Quadrate {
public:
    square(double a = 20, double A = 90) : Quadrate(a, a, a, a, A, A, A, A) {
        name = "Квадрат";
    }
    void print() {
        print_info();
    }
};

// Параллелограмм - стороны папарно равны, углы не равны 90 градусов но попарно равны
class parallelogram : public Quadrate {
public:
    parallelogram(double a = 20, double b = 30, double A = 30, double B = 40) : Quadrate(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм";
    }
    void print() {
        print_info();
    }
};

//ромб(все стороны равны, углы A, C и B, D попарно равны).
class rhombus : public Quadrate {
public:
    rhombus(double a=30, double A=30, double B=40) : Quadrate(a, a, a, a, A, B, A, B) {
        name = "Ромб";
    }
    void print() {
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
    void print_info() {
        F_print(name);
        std::cout << "Стороны: " << "a=" << a << ' ' << "b=" << b << ' ' << "c=" << c << std::endl;
        std::cout << "Углы: " << "A=" << A << ' ' << "B=" << B << ' ' << "C=" << C << std::endl;
    }
};

// Прямоугольный треугольник - треугольник у которого один угол = 90
class right_triangle : public Triangle {
public:
    right_triangle(double a=10, double b=20, double c = 30, double A = 50, double B = 60, double C = 90) : Triangle(a, b, c, A, B, C) {
        name = "Прямоугольный треугольник";
    }
    void print() {
        print_info();
    }
};

// Равнобедренный треугольник - треугольник у которого две стороны и два угла равны
class isosceles_triangle : public Triangle {
public:
    isosceles_triangle(double a = 10, double b = 20, double A = 50, double B = 60) : Triangle(a, b, a, A, B, A) {
        name = "Равнобедренный треугольник";
    }
    void print() {
        print_info();
    }
};

// Равносторонний треугольник - треугольник у которого все стороны и углы равны
class equilateral_triangle : public Triangle {
public:
    equilateral_triangle(double a = 30, double A = 60) : Triangle(a, a, a, A, A, A) {
        name = "Равносторонний треугольник";
    }
    void print() {
        print_info();
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    Triangle Tr;
    Tr.print_info();
    right_triangle Rt;
    Rt.print();
    isosceles_triangle It;
    It.print();
    equilateral_triangle Et;
    Et.print();
    Quadrate Q;
    Q.print_info();
    rectangle Re;
    Re.print();
    square Sq;
    Sq.print();
    parallelogram Pa;
    Pa.print();
    rhombus R;
    R.print();


    return EXIT_SUCCESS;
}