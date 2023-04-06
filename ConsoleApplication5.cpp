#include <iostream>

class Triangle {
private:
    double a, b, c;

public:
    Triangle() : a(0), b(0), c(0) {}

    Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {}

    double getSideA() const { return a; }
    double getSideB() const { return b; }
    double getSideC() const { return c; }

    void setSideA(double side) { a = side; }
    void setSideB(double side) { b = side; }
    void setSideC(double side) { c = side; }

    double getArea() const {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    void print_sqr() const {
        std::cout << "Side A: " << a << std::endl;
        std::cout << "Side B: " << b << std::endl;
        std::cout << "Side C: " << c << std::endl;
        std::cout << "Area: " << getArea() << std::endl;
    }
};

int main() {
    Triangle t(6, 8, 10);
    t.print_sqr();
    return 0;
}