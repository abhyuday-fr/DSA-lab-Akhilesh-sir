#include <iostream>
using namespace std;

struct Customer {
    string name;
    int account_no;
    float balance;
};

void printLowBalance(Customer customers[], int size) {
    cout << "\nCustomers with balance less than $200:\n";
    for (int i = 0; i < size; i++) {
        if (customers[i].balance < 200) {
            cout << customers[i].name << endl;
        }
    }
}

void updateHighBalance(Customer customers[], int size) {
    cout << "\nUpdated balances for customers with more than $1000:\n";
    for (int i = 0; i < size; i++) {
        if (customers[i].balance > 1000) {
            customers[i].balance += 100;
            cout << customers[i].name << " - $" << customers[i].balance << endl;
        }
    }
}

int main() {
    const int SIZE = 11;
    Customer customers[SIZE];

    cout << "Enter details of " << SIZE << " customers:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nCustomer " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> customers[i].name;
        cout << "Account Number: ";
        cin >> customers[i].account_no;
        cout << "Balance: $";
        cin >> customers[i].balance;
    }

    printLowBalance(customers, SIZE);
    updateHighBalance(customers, SIZE);

    return 0;
}
