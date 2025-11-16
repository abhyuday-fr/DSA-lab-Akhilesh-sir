#include <iostream>
#include <vector>

namespace search{
    int linear(std::vector<int>&arr,int x){
        for(int i=0;i<arr.size();i++){
            if(x==arr[i]){
                return i;
            }
        }
        return -1;
    }

    int binary(std::vector<int>&arr,int x,int low,int high){
        while(low<=high){
            int mid{(low+high)/2};
            if(arr[mid]==x){
                return mid;
            }
            else{
                if(x<arr[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return -1;
    }

    int IndexSequential(std::vector<int>&arr,int x){
        int low=0;
        int high=arr.size()-1;
        if(x<arr[low] || x>arr[high]){
            return -1;
        }
        else{
            int i=low;
            while(i<high && x>arr[i]){
                i+=4;
            }
            if(x==arr[i]){
                return i;
            }
            else{
                int li=i-1;
                int fi=i-4+1;
                for(int j=fi;j<li;j++){
                    return j;
                }
                return -1;
            }
        }
        return -1;
    }
}

int main(){
    int n{};
    std::cout << "Size: ";
    std::cin >> n;
    std::cout << "Enter elements: ";
    std::vector<int> arr(n);
    for(int i=0;i<n;i++){
        std::cin >> arr[i];
    }

    int elem{},choice{},pos{};
    std::cout << "Enter element to find: ";
    std::cin >> elem;
    std::cout << "Which way to search?\n1. Linear Search\n2. Binary Search\n3. Index Sequencial Search\nYour choice? : ";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        pos=search::linear(arr,elem);
        break;
    
    case 2:
        pos=search::binary(arr,elem,0,n-1);
        break;
    
    case 3:
        pos=search::IndexSequential(arr,elem);
        break;

    default:
        std::cout << "Enter valid number\n";
    }
    pos>=0?std::cout << "Element found at index: " << pos : std::cout << "Element not found";
    std::cout << '\n';
}