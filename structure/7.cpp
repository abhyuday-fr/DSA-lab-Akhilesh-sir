#include <iostream>
using namespace std;

struct Marks {
    int roll_no;
    string name;
    int chem_marks;
    int maths_marks;
    int phy_marks;
};

int main() {
    Marks students[5];

    for (int i = 0; i < 5; i++) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> students[i].roll_no;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Chemistry Marks: ";
        cin >> students[i].chem_marks;
        cout << "Mathematics Marks: ";
        cin >> students[i].maths_marks;
        cout << "Physics Marks: ";
        cin >> students[i].phy_marks;
        cout << endl;
    }

    cout << "Student Percentages:\n";
    for (int i = 0; i < 5; i++) {
        float total = students[i].chem_marks + students[i].maths_marks + students[i].phy_marks;
        float percentage = (total / 300.0) * 100;
        cout << "Roll No: " << students[i].roll_no
             << ", Name: " << students[i].name
             << ", Percentage: " << percentage << "%\n";
    }

    return 0;
}
