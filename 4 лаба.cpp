#include <iostream>
#include <cstdlib>

using namespace std;

class IntArray {
private:
    int size;
    int* data;
public:
    // Конструктор
    IntArray(int size) {
        this->size = size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 8 * i + 5 * i - 2;
        }
    }

    // Деструктор
    ~IntArray() {
        delete[] data;
        cout << "IntArray destroyed" << endl;
    }

    // Метод, що повертає розмір масиву
    int get_size() const {
        return size;
    }

    // Метод, що повертає елемент масиву за індексом
    int get_element(int index) const {
        return data[index];
    }
};

// Функція, що рахує кількість непарних елементів масиву
int count_odd(const IntArray& arr) {
    int count = 0;
    for (int i = 0; i < arr.get_size(); i++) {
        if (arr.get_element(i) % 2 != 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid array size" << endl;
        return 1;
    }

    IntArray arr(size);

    cout << "The array is: ";
    for (int i = 0; i < size; i++) {
        cout << arr.get_element(i) << " ";
    }
    cout << endl;

    int odd_count = count_odd(arr);
    cout << "Number of odd elements: " << odd_count << endl;

    return 0;
}
