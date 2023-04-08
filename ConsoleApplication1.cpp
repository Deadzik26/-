#include <list>
#include <iostream>
#include <fstream>

using namespace std;

class School {
private:
    string Sur;
    string Name;
    double Score[3];
public:
    // Конструктор з параметрами
    School(string S, string N, double M, double P, double I);
    // Метод який перевіряє на наявіність відмінних оцінок
    bool Excelent() const;
    // Метод сортування за ім'ям
    bool operator <(const School& obj) const;
    // Метод повернення ім'я
    string GetName() const;
};

// Конструктор з параметрами
School::School(string S, string N, double M, double P, double I) {
    this->Sur = S;
    this->Name = N;
    this->Score[0] = M;
    this->Score[1] = P;
    this->Score[2] = I;
}
// Метод який перевіряє на наявіність відмінних оцінок
bool School::Excelent() const {
    return (this->Score[0] == 5 || this->Score[1] == 5 || this->Score[2] == 5);
}
// Метод сортування за ім'ям
bool School::operator <(const School& obj) const {
    return this->Name < obj.Name;
}
// Метод повернення ім'я
string School::GetName() const {
    return this->Name;
}
int main() {
    string Sur;
    string Name;
    double Score[3];
    list<School> Students;
    ifstream in("data.txt");
    if (!in) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }
    while (in >> Sur >> Name >> Score[0] >> Score[1] >> Score[2]) {
        School x(Sur, Name, Score[0], Score[1], Score[2]);
        Students.push_back(x);
    }
    Students.sort();
    cout << "Do not have any twos or threes:" << endl;
    for (const School& n : Students) {
        if (!n.Excelent() && Score[0] != 2 && Score[1] != 2 && Score[2] != 2
            && Score[0] != 3 && Score[1] != 3 && Score[2] != 3) {
            cout << n.GetName() << endl;
        }
    }
    return 0;
}
