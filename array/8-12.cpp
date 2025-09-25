#include <iostream>
#include<vector>
using namespace std;

//8.
vector<int>MergeArrays(vector<int> &arr1,vector<int> &arr2){
    vector<int>arr3(arr1.size()+arr2.size());
    int i=0;
    int j=0;
    int k=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            arr3[k]=arr1[i];
            i++;
            k++;
        }
        else{
            arr3[k]=arr2[j];
            j++;
            k++;
        }
    }
    while(i<arr1.size()){
        arr3[k]=arr1[i];
        i++;
        k++;
    }
    while(j<arr2.size()){
        arr3[k]=arr2[j];
        j++;
        k++;
    }
    return arr3;
}

//9.
vector<int> Union(const vector<int> &arr1, const vector<int> &arr2) {
    vector<int> arr3;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            if (arr3.empty() || arr3.back() != arr1[i])
                arr3.push_back(arr1[i]);
            i++;
        } else if (arr2[j] < arr1[i]) {
            if (arr3.empty() || arr3.back() != arr2[j])
                arr3.push_back(arr2[j]);
            j++;
        } else {
            if (arr3.empty() || arr3.back() != arr1[i])
                arr3.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    while (i < arr1.size()) {
        if (arr3.empty() || arr3.back() != arr1[i])
            arr3.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {
        if (arr3.empty() || arr3.back() != arr2[j])
            arr3.push_back(arr2[j]);
        j++;
    }
    return arr3;
}

 //10.
 vector<int> Intersection(const vector<int> &arr1, const vector<int> &arr2) {
    vector<int> arr3;
    int i = 0, j = 0,k=0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr1[i]) {
            j++;
        } else {
            arr3[k]=arr1[i];
            i++;
            j++;
            k++;
        }
    }

    return arr3;
}

//11.
vector<int> SetDifference(const vector<int> &arr1, const vector<int> &arr2) {
    vector<int> result;
    int i = 0, j = 0;
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] < arr2[j]) {
            if(result.empty() || result.back() != arr1[i])
                result.push_back(arr1[i]);
            i++;
        } else if(arr2[j] < arr1[i]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    while(i < arr1.size()) {
        if(result.empty() || result.back() != arr1[i])
            result.push_back(arr1[i]);
        i++;
    }
    return result;
}

//12.
vector<int> SymmetricDifference(const vector<int> &arr1, const vector<int> &arr2) {
    vector<int> result;
    int i = 0, j = 0;
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] < arr2[j]) {
            if(result.empty() || result.back() != arr1[i])
                result.push_back(arr1[i]);
            i++;
        } else if(arr2[j] < arr1[i]) {
            if(result.empty() || result.back() != arr2[j])
                result.push_back(arr2[j]);
            j++;
        } else {
            i++;
            j++;
        }
    }
    while(i < arr1.size()) {
        if(result.empty() || result.back() != arr1[i])
            result.push_back(arr1[i]);
        i++;
    }
    while(j < arr2.size()) {
        if(result.empty() || result.back() != arr2[j])
            result.push_back(arr2[j]);
        j++;
    }
    return result;
}


int main(){
    int n1,n2;
    cout << "Enter size of first sorted array: ";
    cin >> n1;
    cout << "Enter elements: ";
    vector<int>arr1(n1);
    for(int i=0;i<n1;i++){
        cin >> arr1[i];
    }
    cout << "Enter size of second sorted array: ";
    cin >> n2;
    cout << "Enter elements: ";
    vector<int>arr2(n2);
    for(int i=0;i<n2;i++){
        cin >> arr2[i];
    }
    vector<int>arr3=MergeArrays(arr1,arr2);
    for(auto num:arr3){
        cout << num << " ";
    }
    arr3=Union(arr1,arr2);
    for(auto num:arr3){
        cout << num << " ";
    }
    arr3=Intersection(arr1,arr2);
    for(auto num:arr3){
        cout << num << " ";
    }
    arr3=SetDifference(arr1,arr2);
    for(auto num:arr3){
        cout << num << " ";
    }
    arr3=SymmetricDifference(arr1,arr2);
    for(auto num:arr3){
        cout << num << " ";
    }
    return 0;
}