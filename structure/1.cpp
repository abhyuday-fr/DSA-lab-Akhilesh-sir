#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct student
{
    string name;
    float marks[6];
    int roll;
};
int main(){
    student s;
    cout << "Enter Student name: ";
    cin >> s.name;
    cout << "Enter Student roll no. ";
    cin >> s.roll;
    cout << "Enter marks of student in 6 subjects: ";
    for(int i=0;i<6;i++){
        cin >> s.marks[i];
    }
    float min1=s.marks[0];
    float min2=s.marks[0];
    for(int i=0;i<6;i++){
        if(s.marks[i]<min1){
            min1=s.marks[i];
        }
    }
    for(int i=0;i<6;i++){
        if(s.marks[i]==min1){
            continue;
        }
        if(s.marks[i]<min2){
            min2=s.marks[i];
        }
    }
    float total=0,per;
    cout << "Best 4 marks are: ";
    for(auto mark : s.marks){
        if(mark==min1 || mark==min2){
            continue;
        }
        cout << mark << " ";
        total+=mark;
    }
    per=total/4;
    cout << "\nPercentage of Best 4 is: " << per;
    per>95?cout << "\nCongratulations!! You are accepted to DU" : cout << "\nSorry, you are not accepted to DU";

    return 0;
}