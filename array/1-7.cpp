#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//1.
void Traverse(vector<int> &arr){
    for(auto num : arr){
        cout << num << " ";
    }
    cout << '\n';
}

//2.
void Insert(vector<int> &arr, int pos, int x){
    int temp=arr[arr.size()-1];
    for(int i=arr.size()-1;i>pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=x;
    arr.push_back(temp);
    arr.shrink_to_fit();
}

//3.
void InsertionSorted(vector<int> &arr,int x){
    if (arr.empty() || x >= arr.back()) {
        arr.push_back(x);
        return;
    }
    int i = 0;
    while (i < arr.size() && arr[i] < x) {
        i++;
    }

    Insert(arr,i,x);
}

//4.
int Delete(vector<int> &arr,int pos){
    int x=arr[pos];
    for(int i=pos;i<arr.size()-1;i++){
        arr[i]=arr[i+1];
    }
    arr.pop_back();
    return x;
}

//5.
void MissingNum(int B[],int n){
    int max=B[0];
    for(int i=1;i<n;i++){
        if(B[i]>max){
            max=B[i];
        }
    }
    vector<int>DAT(max+1);
    int i=0;
    while(i<n){
        DAT[B[i]]=1;
        i++;
    }
    i=1;
    cout << "Missing numbers are: ";
    while(i<max+1){
        if(DAT[i]==0){
            cout << i << " ";
        }
    }
    cout << '\n';

}

//6.
void RepeatingNum(vector<int> &arr,int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    vector<int>DAT(max+1);
    int i=0;
    while(i<n){
        DAT[arr[i]]+=1;
        i++;
    }
    while(i<max+1){
        cout << i << " - " << DAT[i];
    }
    cout << '\n';

}

//7.
void Reverse(vector<int> &arr){
    int i=0;
    int j=arr.size()-1;
    while(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}

int main(){
    int n,pos,x;
    cout << "Enter size of array: ";
    cin >> n;
    vector <int> A(n);
    cout << "Enter Elements: ";
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    cout << "Position and Element to insert respectively: ";
    cin >> pos >> x;

    Insert(A,pos,x);
    Traverse(A);

    sort(A.begin(),A.end());
    cout << "sorted array: ";
    Traverse(A);
    cout << "Enter element to insert in this array: ";
    cin >> x;
    InsertionSorted(A,x);
    Traverse(A);

    cout << "Enter position of element to delete from the array: ";
    cin >> pos;
    Delete(A,pos);
    Traverse(A);

    cout << "Reverse of array: ";
    Reverse(A);
    Traverse(A);

    return 0;
}