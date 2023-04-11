#include <iostream>
#include <cmath>

using namespace std;

class Hexagon {
private:
	float sidea;
public:
	Hexagon() {
		this->sidea = 0;
	}

	Hexagon(float sidea) {
		this->sidea = sidea;
	}

	~Hexagon() {
		cout << "Constructor destroyed" << endl;
	}

	void setsidea(float sidea) {
		this->sidea = sidea;
	}

	float getsidea() {
		return this->sidea;
	}

	float getarea() {
		return ((3 * sqrt(3)) / 2) * pow(this->sidea, 2);
	}

	friend Hexagon frd(Hexagon a, Hexagon b);
};

void print_sqrt(Hexagon S) {
	cout << "Sidea: " << S.getsidea() << " area: " << S.getarea() << endl;
}

Hexagon frd(Hexagon a, Hexagon b) {
	float new_sidea = sqrt((a.getarea() + b.getarea()) * 2 / (3 * sqrt(3)));
	Hexagon c = Hexagon(new_sidea);
	return c;
}

int main() {
	float sidea;
	cout << "Write sidea of Hexagon 1: ";
	cin >> sidea;
	Hexagon a = Hexagon(sidea);

	cout << "Write sidea of Hexagon 2: ";
	cin >> sidea;
	Hexagon b = Hexagon(sidea);

	print_sqrt(a);
	print_sqrt(b);

	Hexagon c = frd(a, b);
	print_sqrt(c);
}
