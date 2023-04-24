#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
public:
    Person() {
        name = "Unknown";
    }
    Person(string n) {
        name = n;
    }
    virtual ~Person() {}
    string getName() const { return name; }
};

class Employee : public Person {
protected:
    double salary;
public:
    Employee() : Person() {
        salary = 0;
    }
    Employee(string n, double s) : Person(n) {
        salary = s;
    }
    virtual ~Employee() {}
    double getSalary() const { return salary; }
};

class Worker : public Employee {
protected:
    int hours;
public:
    Worker() : Employee() {
        hours = 0;
    }
    Worker(string n, double s, int h) : Employee(n, s) {
        hours = h;
    }
    virtual ~Worker() {}
    int getHours() const { return hours; }
};

class Engineer : public Employee {
protected:
    string specialty;
public:
    Engineer() : Employee() {
        specialty = "Unknown";
    }
    Engineer(string n, double s, string sp) : Employee(n, s) {
        specialty = sp;
    }
    virtual ~Engineer() {}
    string getSpecialty() const { return specialty; }
};

int main() {
    Person p("John Smith");
    Employee e("Jane Doe", 50000);
    Worker w("Bob Johnson", 30000, 40);
    Engineer en("Alice Lee", 75000, "Software Engineering");

    cout << "Person name: " << p.getName() << endl;
    cout << "Employee name: " << e.getName() << ", salary: " << e.getSalary() << endl;
    cout << "Worker name: " << w.getName() << ", salary: " << w.getSalary() << ", hours: " << w.getHours() << endl;
    cout << "Engineer name: " << en.getName() << ", salary: " << en.getSalary() << ", specialty: " << en.getSpecialty() << endl;

    return 0;
}
