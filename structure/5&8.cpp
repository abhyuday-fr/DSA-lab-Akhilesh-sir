#include <iostream>
using namespace std;
struct complex{
    float real;
    float imaginary;
};

void addition(float x1,float y1,float x2,float y2){
    cout << "(a+ib) + (x+iy) = " << x1+x2 << "+i(" << y1+y2 << ")\n"; 
}

void difference(float x1,float y1,float x2,float y2){
    cout << "(a+ib) - (x+iy) = " << x1-x2 << "+i(" << y1-y2 << ")\n"; 
}

void multiplication(float x1,float y1,float x2,float y2){
    cout << "(a+ib) X (x+iy) = " << (x1*x2)-(y1*y2) << "+i(" << (x1*y2)+(x2*y1) << ")\n";
}

int main(){
    complex c1,c2,c3;
    c1.real=0;
    c1.imaginary=0;
    c2.real=0;
    c2.imaginary=0;
    char exp[10];
    cout << "Enter first complex number in a+ib format: ";
    cin >> exp;
    int i=0;
    while(exp[i]!='+'){
        c1.real=c1.real*10 + (exp[i]-'0');
        i++;
    }
    i=i+2;
    while(exp[i]!='\0'){
        c1.imaginary=c1.imaginary*10 + (exp[i]-'0');
        i++;
    }
    
    cout << "\nEnter second complex number in x+iy format: ";
    cin >> exp;
    i=0;
    while(exp[i]!='+'){
        c2.real=c2.real*10 + (exp[i]-'0');
        i++;
    }
    i=i+2;
    while(exp[i]!='\0'){
        c2.imaginary=c2.imaginary*10 + (exp[i]-'0');
        i++;
    }
    
    addition(c1.real,c1.imaginary,c2.real,c2.imaginary);
    difference(c1.real,c1.imaginary,c2.real,c2.imaginary);
    multiplication(c1.real,c1.imaginary,c2.real,c2.imaginary);
    
    
    return 0;
}