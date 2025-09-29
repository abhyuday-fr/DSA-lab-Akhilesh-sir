#include <iostream>
using namespace std;

struct Student {
    int roll_no;
    string name;
    int age;
    string address;
};

void printAge14(Student students[], int size) {
    cout << "\nStudents aged 14:\n";
    for (int i = 0; i < size; i++) {
        if (students[i].age == 14) {
            cout << students[i].name << endl;
        }
    }
}

void printEvenRoll(Student students[], int size) {
    cout << "\nStudents with even roll numbers:\n";
    for (int i = 0; i < size; i++) {
        if (students[i].roll_no % 2 == 0) {
            cout << students[i].name << endl;
        }
    }
}

void displayByRoll(Student students[], int size, int roll) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (students[i].roll_no == roll) {
            cout << "\nDetails of student with roll no " << roll << ":\n";
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Address: " << students[i].address << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\nNo student found with roll no " << roll << endl;
    }
}

int main() {
    const int SIZE = 11;
    Student students[SIZE];

    cout << "Enter details of " << SIZE << " students:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> students[i].roll_no;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Age (11 to 14): ";
        cin >> students[i].age;
        cout << "Address: ";
        cin.ignore(); // Clear newline before getline
        getline(cin, students[i].address);
    }

    printAge14(students, SIZE);
    printEvenRoll(students, SIZE);

    int search_roll;
    cout << "\nEnter roll number to search: ";
    cin >> search_roll;
    displayByRoll(students, SIZE, search_roll);

    return 0;
}
