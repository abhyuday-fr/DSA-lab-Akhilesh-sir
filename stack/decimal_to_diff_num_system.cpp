#include <iostream>
#include "stack_functions.hpp"

//The STACK and the STACKSIZE must be initialized in the Header File "stack_functions.hpp"

using namespace std;

void Binary(int n){
    Initialize();
    while(n!=0){
        int r=n%2;
        n=n/2;
        Push(r);
    }
    while(!IsEmpty()){
        int x=Pop();
        cout << x;
    }
}
void Octal(int n){
    Initialize();
    while(n!=0){
        int r=n%8;
        n=n/8;
        Push(r);
    }
    while(!IsEmpty()){
        int x=Pop();
        cout << x;
    }
}
void Hexa(int n){
    Initialize();
    char DAT[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(n!=0){
        int r=n%16;
        n=n/16;
        Push(r);
    }
    while(!IsEmpty()){
        int x=Pop();
        cout << DAT[x];
    }
}

int main(){
    int num;
    cout << "Enter Decimal NUmber: ";
    cin >> num;
    cout << "What number system you want to conver?\n1. Binary\n2. Octal\n3. Hexadecimal?\nEnter option number(1-3): ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
          Binary(num);
        break;
        case 2:
           Octal(num);
        break;
        case 3:
           Hexa(num);
        break;
        default:
          cout << "Enter valid number from the options (1-3)";
    }
    return 0;
}