// Задача 3. Фигуры. Методы

#include <iostream>
#include <string>
// Базовый класс Фигура
class Figure {
protected:
    std::string name;
    int size;
public:
    Figure(int size, std::string name = "Фигура") {
        this->name = name;
        this->size = size;
    }
    bool check() {
        if (size == 0) return true;
        else return false;
    }
    virtual std::string print_info() {
        std::string F_name = name + ": \n";
        std::string p_check;
        if (check() == true) p_check = "Правильная\n";
        else p_check = "Неправильная\n";
        std::string p_size = "Количество сторон: " + std::to_string(size) + "\n";
        return F_name + p_check + p_size;
    }
};
// Треугольник
class Triangle : public Figure {
protected:
    std::string name;
    int size;
    int a{}, b{}, c{}; // Стороны
    int A{}, B{}, C{}; // Углы
public:
    Triangle(int size, int a, int b, int c, int A, int B, int C, std::string name = "Треугольник") : Figure(size, name) {
        this->name = name;
        this->size = size;
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    virtual bool check() {
        if (size == 3 && A+B+C == 180) return true;
        else return false;
    }
    std::string print_info() override {
        std::string F_name = name + ": \n";
        std::string p_check;
        if (check() == true) { p_check = "Правильная\n"; }
        else {p_check = "Неправильная\n";}
        std::string p_size = "Количество сторон: " + std::to_string(size) + "\n";
        std::string p_side = "Стороны: a= " + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + "\n";
        std::string p_angles = "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + "\n";
        return F_name + p_check + p_size + p_side + p_angles;
    }
};
// Прямоугольный треугольник
class Triangle_Right : public Triangle {
public:
    Triangle_Right(int size, int a, int b, int c, int A, int B, int C, std::string name = "Прямоугольный треугольник") : Triangle(size, a, b, c, A, B, C, name) {
    }
    bool check() override {
        if (size == 3 && A + B + C == 180 && C ==90) return true;
        else return false;
    }
    std::string print_info() override {
        return Triangle::print_info();
    }
};
// Равнобедренный треугольник
class Triangle_Isosceles : public Triangle {
public:
    Triangle_Isosceles(int size, int a, int b, int c, int A, int B, int C, std::string name = "Равнобедренный треугольник") : Triangle(size, a, b, c, A, B, C, name) {
    }
    bool check() override {
        if (size == 3 && A + B + C == 180 && a==c && A==C) return true;
        else return false;
    }
    std::string print_info() override {
        return Triangle::print_info();
    }
};
// Равносторонний треугольник
class Triangle_Equilateral : public Triangle {
public:
    Triangle_Equilateral(int size, int a, int b, int c, int A, int B, int C, std::string name = "Равносторонний треугольник") : Triangle(size, a, b, c, A, B, C, name) {
    }
    bool check() override {
        if (size == 3 && A + B + C == 180 && a == b && b == c && A == B && B == C && C == 60) return true;
        else return false;
    }
    std::string print_info() override {
        return Triangle::print_info();
    }
};
// Четырехугольник - базовый для всех четырехугольников
class Quadrate : public Figure {
protected:
    std::string name;
    int size;
    int a{}, b{}, c{}, d{}; // Стороны
    int A{}, B{}, C{}, D{}; // Углы
public:
    Quadrate(int size, int a, int b, int c, int d, int A, int B, int C, int D, std::string name = "Четырехугольник") : Figure(size, name) {
        this->name = name;
        this->size = size;
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    virtual bool check() {
        if (size == 4 && A+B+C+D==360) return true;
        else return false;
    }
    std::string print_info() override {
        std::string F_name = name + ": \n";
        std::string p_check;
        if (check() == true) p_check = "Правильная\n";
        else p_check = "Неправильная\n";
        std::string p_size = "Количество сторон: " + std::to_string(size) + "\n";
        std::string p_side = "Стороны: a= " + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + " d=" + std::to_string(d) + "\n";
        std::string p_angles = "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + " D=" + std::to_string(D) + "\n";
        return F_name + p_check + p_size + p_side + p_angles;
    }
};
// Прямоугольник
class Quadrate_Rectangle : public Quadrate {
public:
    Quadrate_Rectangle(int size, int a, int b, int c, int d, int A, int B, int C, int D, std::string name = "Прямоугольник") : Quadrate(size, a, b, c, d, A, B, C, D, name) {
    }
    bool check() override {
        if (size == 4 && A + B + C + D == 360 && A == B && B== C && C == D && D == 90 && a == c && b == d) return true;
        else return false;
    }
    std::string print_info() override {
        return Quadrate::print_info();
    }
};
// Квадрат
class Quadrate_Square : public Quadrate {
public:
    Quadrate_Square(int size, int a, int b, int c, int d, int A, int B, int C, int D, std::string name = "Квадрат") : Quadrate(size, a, b, c, d, A, B, C, D, name) {
    }
    bool check() override {
        if (size == 4 && A + B + C + D == 360 && A == B && B == C && C == D && C == 90 && a == b && b == c && c == d) return true;
        else return false;
    }
    std::string print_info() override {
        return Quadrate::print_info();
    }
};
// Паралелограмм
class Quadrate_Parallelogram : public Quadrate {
public:
    Quadrate_Parallelogram(int size, int a, int b, int c, int d, int A, int B, int C, int D, std::string name = "Параллелограмм") : Quadrate(size, a, b, c, d, A, B, C, D, name) {
    }
    bool check() override {
        if (size == 4 && A + B + C + D == 360 && A == C && B == D && a == c && b == d) return true;
        else return false;
    }
    std::string print_info() override {
        return Quadrate::print_info();
    }
};
// Ромб
class Quadrate_Rhombus : public Quadrate {
public:
    Quadrate_Rhombus(int size, int a, int b, int c, int d, int A, int B, int C, int D, std::string name = "ромб") : Quadrate(size, a, b, c, d, A, B, C, D, name) {
    }
    bool check() override {
        if (size == 4 && A + B + C + D == 360 && A == C && B == D && a == b && b == c && c == d) return true;
        else return false;
    }
    std::string print_info() override {
        return Quadrate::print_info();
    }
};
// Функция вывода на экран
void print(Figure& figure) {
    std::cout << figure.print_info() << std::endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    Figure F(0);
    print(F);
    Triangle T(3, 10, 20, 30, 50, 60, 40); // Треугольник
    print(T);
    Triangle_Right Rt(3, 10, 20, 30, 40, 50, 90); // Прямоугольный треугольник
    print(Rt);
    Triangle_Isosceles It(3, 20, 10, 20, 30, 120, 30); // Равнобедренный треугольник
    print(It);
    Triangle_Equilateral Et(3, 20, 20, 20, 60, 60, 60); // Равносторонний треугольник
    print(Et);
    Quadrate Q(4, 10, 20, 30, 40, 50, 60, 70, 80); // Четырехугольник
    print(Q);
    Quadrate_Rectangle R(4, 20, 30, 20, 30, 90, 90, 90, 90); // Прямоугольник
    print(R);
    Quadrate_Square Sq(4, 40, 40, 40, 40, 90, 90, 90, 90); // Квадрат
    print(Sq);
    Quadrate_Parallelogram P(4, 30, 40, 30, 40, 50, 60, 50, 60); // Паралелограмм
    print(P);
    Quadrate_Rhombus Rh(4, 50, 50, 50, 50, 45, 135, 45, 135); // Ромб
    print(Rh);
    
    return EXIT_SUCCESS;
}

