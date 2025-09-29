#include <iostream>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

int main() {
    Date d1, d2;

    cout << "Enter first date (day month year): ";
    cin >> d1.day >> d1.month >> d1.year;

    cout << "Enter second date (day month year): ";
    cin >> d2.day >> d2.month >> d2.year;

    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year) {
        cout << "Dates are equal\n";
    } else {
        cout << "Dates are not equal\n";
    }

    return 0;
}
