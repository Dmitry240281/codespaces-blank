//Задача 1. Фигуры.Количество сторон

#include <iostream>

class FigureParent {
    int side;
    std::string figure;
public:
    void get_sides_count(std::string figure, int side) {
        this->side = side;
        this->figure = figure;
    }
    void print(std::string figure, int side) {
        std::cout << figure << ": " << side << std::endl;
    }
};

class Figure: public FigureParent {
    int side = 0;
    std::string figure = "Фигура";
public:
    Figure() { get_sides_count(figure, side); }
    void F_print() {
        print(figure, side);
        }
    
};

class Triangle: public FigureParent {
    int side = 3;
    std::string figure = "Треугольник";
public:
    Triangle() { get_sides_count(figure, side); }
    void F_print() {
        print(figure, side);
    }

};

class Quadrilateral: public FigureParent {
    int side = 4;
    std::string figure = "Четырехугольник";
public:
    Quadrilateral() { get_sides_count(figure, side); }
    void F_print() {
        print(figure, side);
    }

};

int main()
{
    setlocale(LC_ALL, "rus");
    Figure F;
    F.F_print();
    Triangle T;
    T.F_print();
    Quadrilateral Q;
    Q.F_print();

    return EXIT_SUCCESS;
}

