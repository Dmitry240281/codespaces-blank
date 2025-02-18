//Задача 1. Фигуры.Количество сторон

#include <iostream>

class FigureParent {
    int side;
    std::string name;
public:
    void set_sides_count(std::string figure, int side) {
        this->side = side;
        this->name = name;
    }
    void get_side_count (std::string name, int side) const {
        std::cout << name << ": " << side << std::endl;
    }
};

class Figure: public FigureParent {
    int side = 0;
    std::string name = "Фигура";
public:
    Figure() { set_sides_count(name, side); }
    void get_print() const {
        get_side_count(name, side);
        }
    
};

class Triangle: public FigureParent {
    int side = 3;
    std::string name = "Треугольник";
public:
    Triangle() { set_sides_count(name, side); }
    void get_print() const {
        get_side_count(name, side);
    }

};

class Quadrilateral: public FigureParent {
    int side = 4;
    std::string name = "Четырехугольник";
public:
    Quadrilateral() { set_sides_count(name, side); }
    void get_print() {
        get_side_count(name, side);
    }

};

int main()
{
    setlocale(LC_ALL, "rus");
    Figure F;
    F.get_print();
    Triangle T;
    T.get_print();
    Quadrilateral Q;
    Q.get_print();

    return EXIT_SUCCESS;
}

