#include <iostream>
using namespace std;

struct Employee {
    string name;
    float salary;
    int hours_per_day;
};

int main() {
    const int SIZE = 10;
    Employee employees[SIZE];

    cout << "Enter details of " << SIZE << " employees:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nEmployee " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "Salary: $";
        cin >> employees[i].salary;
        cout << "Hours of work per day: ";
        cin >> employees[i].hours_per_day;
    }

    for (int i = 0; i < SIZE; i++) {
        if (employees[i].hours_per_day == 8) {
            employees[i].salary += 50;
        }
    }

    cout << "\nFinal Salaries of Employees:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << employees[i].name << " - $" << employees[i].salary << endl;
    }

    return 0;
}
