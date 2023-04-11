#include <iostream>
#include <cmath>

class Triangle {
private:
    double a, b, c; // сторони трикутника
public:
    // конструктори
    Triangle() : Triangle(0, 0, 0) {}
    Triangle(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {}

    // методи доступу до сторін трикутника
    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    void set_a(double a_) { a = a_; }
    void set_b(double b_) { b = b_; }
    void set_c(double c_) { c = c_; }

    // обчислення площі трикутника за формулою Герона
    double area() const {
        double p = (a + b + c) / 2;
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    }

    // перевантаження операції <<
    friend std::ostream& operator<<(std::ostream& os, const Triangle& t) {
        return os << "Triangle sides: " << t.a << ", " << t.b << ", " << t.c << "\n"
            << "Triangle area: " << t.area() << "\n";
    }

    // перевантаження операції +
    friend Triangle operator+(const Triangle& t1, const Triangle& t2) {
        return Triangle(t1.a + t2.a, t1.b + t2.b, t1.c + t2.c);
    }

    // перевантаження операції ++
    Triangle& operator++() {
        ++a, ++b, ++c;
        return *this;
    }
};

int main() {
    Triangle t1(3, 4, 5);
    Triangle t2(6, 8, 10);

    std::cout << "t1: " << t1 << "\n"
        << "t2: " << t2 << "\n";

    Triangle t3 = t1 + t2;
    std::cout << "t3: " << t3 << "\n";

    ++t1;
    std::cout << "t1 after increment: " << t1 << "\n";

    return 0;
}
