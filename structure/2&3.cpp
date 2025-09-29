#include <iostream>
using namespace std;
struct student{
    string name,address;
    int roll;
    int age;
    float marks;
}s[5];
int main(){
    cout << "Enter following details of 15 students in order\n";
    for(int i=0;i<5;i++){
        cout << "student " << i+1 << '\n';
        cout << "name: ";
        cin >> s[i].name;
        cout << "roll number: ";
        cin >> s[i].roll;
        cout << "age: ";
        cin >> s[i].age;
        cout << "marks: ";
        cin >> s[i].marks;
        cout << "address: ";
        cin >> s[i].address;
        cout << '\n';
    }
    cout << "details of student 1 are\n";
    cout << s[0].name << " " << s[0].roll << " " << s[0].age << " " << s[0].marks;
    return 0;
}