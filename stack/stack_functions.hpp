//I have created this header file so that I don't have to 
//make primitive stack functions over and over again

#include <iostream>
#define STACKSIZE 10
using namespace std;
struct stk{
    int ITEM[STACKSIZE];
    int TOP;
};

struct stk S;

void Initialize(){
    S.TOP=-1;
}

bool IsEmpty(){
    if (S.TOP==-1) return true;
    else return false;
}

void Push(int x){
    if(S.TOP==STACKSIZE-1){
        cout << "Stack Overflow";
        exit(1);
    }
    else{
        S.TOP=S.TOP+1;
        S.ITEM[S.TOP]=x;
    }
}

int Pop(){
    if(IsEmpty()){
        cout << "Stack Underflow";
        exit(1);
    }
    else{
        int x=S.ITEM[S.TOP];
        S.TOP=S.TOP-1;
        return x;
    }
}

int StackTop(){
    return S.ITEM[S.TOP];
}