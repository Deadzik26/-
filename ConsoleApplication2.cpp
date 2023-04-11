#include <iostream>
#include <cmath>

using namespace std;

class Hexagon {
private:
    float side;
public:
    Hexagon() {
        this->side = 0;
    }

    Hexagon(float side) {
        this->side = side;
    }

    ~Hexagon() {
        cout << "Hexagon destroyed" << endl;
    }

    void set_side(float side) {
        this->side = side;
    }

    float get_side() {
        return this->side;
    }

    float get_area() {
        return (3 * sqrt(3) * pow(this->side, 2)) / 2;
    }

    void print_info() {
        cout << "Side: " << this->side << " Area: " << this->get_area() << endl;
    }

    friend Hexagon frd(Hexagon h1, Hexagon h2) {
        float new_side = sqrt((h1.get_area() + h2.get_area()) / ((3 * sqrt(3)) / 2));
        return Hexagon(new_side);
    }
};

int main() {
    float side1, side2;

    cout << "Enter side of first hexagon: ";
    cin >> side1;
    Hexagon h1 = Hexagon(side1);
    h1.print_info();

    cout << "Enter side of second hexagon: ";
    cin >> side2;
    Hexagon h2 = Hexagon(side2);
    h2.print_info();

    Hexagon h3 = frd(h1, h2);
    h3.print_info();

    return 0;
}
