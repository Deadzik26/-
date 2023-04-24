#include <iostream>
#include <cmath>

class Triangle {
private:
    double a, b, c;

public:
    Triangle() : a(0), b(0), c(0) {}
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    void setA(double a) { this->a = a; }
    void setB(double b) { this->b = b; }
    void setC(double c) { this->c = c; }

    double area() const {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    friend std::ostream& operator<<(std::ostream& os, const Triangle& t) {
        os << "Sides: " << t.a << ", " << t.b << ", " << t.c << std::endl;
        os << "Area: " << t.area() << std::endl;
        return os;
    }

    friend Triangle operator+(const Triangle& t1, const Triangle& t2) {
        double a = t1.a + t2.a;
        double b = t1.b + t2.b;
        double c = t1.c + t2.c;
        return Triangle(a, b, c);
    }

    Triangle operator++() {
        ++a;
        ++b;
        ++c;
        return *this;
    }
};

int main() {
    Triangle t1(3, 4, 5);
    Triangle t2(6, 8, 10);

    std::cout << "t1: " << t1 << std::endl;
    std::cout << "t2: " << t2 << std::endl;

    Triangle t3 = t1 + t2;
    std::cout << "t3: " << t3 << std::endl;

    ++t1;
    std::cout << "t1 after increment: " << t1 << std::endl;

    return 0;
}
