#include <iostream>
using namespace std;

struct Distance {
    int feet;
    int inches;
};

int main() {
    Distance d1, d2, sum;

    cout << "Enter first distance:\n";
    cout << "Feet: ";
    cin >> d1.feet;
    cout << "Inches: ";
    cin >> d1.inches;

    cout << "\nEnter second distance:\n";
    cout << "Feet: ";
    cin >> d2.feet;
    cout << "Inches: ";
    cin >> d2.inches;

    sum.feet = d1.feet + d2.feet;
    sum.inches = d1.inches + d2.inches;

    if (sum.inches >= 12) {
        sum.feet += sum.inches / 12;
        sum.inches = sum.inches % 12;
    }

    cout << "\nTotal Distance = " << sum.feet << " feet " << sum.inches << " inches\n";

    return 0;
}
