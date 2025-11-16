#include <iostream>

namespace sort{

    void BubbleSort(int A[],int size){
        for(int i=0;i<size;i++){
            for(int j=0;j<size-i;j++){
                if(A[j]>A[j+1]){
                    int temp=A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                }
            }
        }
    }

    void SelectionSort(int A[],int size){
        for(int i=0;i<size;i++){
            int min=i;
            for(int j=i+1;j<size;j++){
                if(A[j]<A[min]){
                    j=min;
                }
            }
            int temp=A[i];
            A[i]=A[min];
            A[min]=temp;
        }
    }

    void InsertionSort(int A[],int size){
        for(int i=1;i<size;i++){
            int k=A[i];
            int j=i-1;
            while(j>=0 && A[j]>k){
                A[j+1]=A[j];
                j--;
            }
            A[j+1]=k;
        }
    }

    int Partition(int A[],int low,int high){
        int pivot=A[low];
        int i=low;
        int j=high;
        do{
            do{
                i++;
            }while(A[i]<pivot);

            do{
                j--;
            }while(A[j]>pivot);

            if(i<j){
                std::swap(A[i],A[j]);
            }
        }while(i<j);
        std::swap(A[low],A[j]);
        return j;
    }

    int MedianPartition(int A[],int low,int high){
        int i=low;
        int j=high;
        int mid=(low+high)/2;
        std::swap(A[low],A[mid]);
        int pivot=A[low];
        do{
            do{
                i++;
            }while(A[i]<pivot);

            do{
                j--;
            }while(A[j]>pivot);

            if(i<j){
                std::swap(A[i],A[j]);
            }
        }while(i<j);
        std::swap(A[low],A[j]);
        return j;
    }

    void Quicksort(int A[],int low,int high){
        if(low<high){
            int j=sort::Partition(A,low,high);
            sort::Quicksort(A,low,j);
            sort::Quicksort(A,j+1,high);
        }
    }

    void MedianQuickSort(int A[],int low,int high){
        if(low<high){
            int j=sort::MedianPartition(A,low,high);
            sort::Quicksort(A,low,j);
            sort::Quicksort(A,j+1,high);
        }
    }

    int C[9];

    void Merge(int A[],int low,int mid,int high){
        int i=low;int j=mid+1;int k=low;
        while(i<mid && j<=high){
            if(A[i]<A[j]){
                C[k]=A[i];
                i++;
                k++;
            }
            else{
                C[k]=A[j];
                j++;
                k++;
            }
        }
        while(i<=mid){
            C[k]=A[i];
            i++;
            k++;
        }
        while(j<=high){
            C[k]=A[j];
            j++;
            k++;
        }
        for(int i=low;i<high;i++){
            A[i]=C[i];
        }
    }

    void MergeSort(int A[],int low,int high){
        if(low<high){
            int mid=(low+high)/2;
            MergeSort(A,low,mid);
            MergeSort(A,mid+1,high);
            Merge(A,low,mid,high);
        }
    }

    void CountingSort(int A[], int size) {
    int max = A[0];
    for (int i = 1; i < size; i++) {
        if (A[i] > max) max = A[i];
    }
    int* count = new int[max + 1]();
    for (int i = 0; i < size; i++) count[A[i]]++;
    for (int i = 1; i <= max; i++) count[i] += count[i - 1];
    int* output = new int[size];
    for (int i = size - 1; i >= 0; i--) {
        output[--count[A[i]]] = A[i];
    }
    for (int i = 0; i < size; i++) A[i] = output[i];
    delete[] count;
    delete[] output;
    }

    int getMax(int A[], int n) {
    int mx = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > mx)
            mx = A[i];
    return mx;
    }

    void CountSortForRadix(int A[], int n, int exp) {
    int* output = new int[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(A[i]/exp)%10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i-1];
    for (int i = n-1; i >= 0; i--) {
        output[--count[(A[i]/exp)%10]] = A[i];
    }
    for (int i = 0; i < n; i++)
        A[i] = output[i];
    delete[] output;
    }

    void RadixSort(int A[], int n) {
      int m = getMax(A, n);
      for (int exp = 1; m/exp > 0; exp *= 10)
          CountSortForRadix(A, n, exp);
    }



}

int main(){

    int A[10]={71,-71,23,17,0,-3,2,1,10};
    A[9]=INT_MAX;

    //1.Quick Sort
    std::cout << "Quick Sort\n";
    sort::Quicksort(A,0,9);
    for(int i=0;i<9;i++){
        std::cout << A[i] << " ";
    }

    std::cout << '\n';

    //2.Median Quick Sort
    std::cout << "Median Quick Sort\n";
    sort::MedianQuickSort(A,0,9);
    for(int i=0;i<9;i++){
        std::cout << A[i] << " ";
    }
    std::cout << '\n';

    //3.Merge Sort
    std::cout << "Merge sort\n";
    sort::MergeSort(A,0,9);
    for(int i=0;i<9;i++){
        std::cout << A[i] << " ";
    }
    std::cout << '\n';

    //4.Bubble Sort
    std::cout << "Bubble Sort\n";
    sort::BubbleSort(A,9);
    for(int i=0;i<9;i++){
        std::cout << A[i] << " ";
    }
    std::cout << '\n';

    //5.Selection Sort
    std::cout << "Selection Sort\n";
    sort::SelectionSort(A,9);
    for(int i=0;i<9;i++){
        std::cout << A[i] << " ";
    }
    std::cout << '\n';

    //5.Inssertion Sort
    std::cout << "Insertion Sort\n";
    sort::InsertionSort(A,9);
    for(int i=0;i<9;i++){
        std::cout << A[i] << " ";
    }
    std::cout << '\n';

    //6. Counting Sort
    std::cout << "Counting Sort\n";
    sort::CountingSort(A, 9);
    for(int i=0;i<9;i++){
      std::cout << A[i] << " ";
    }
    std::cout << '\n';

    //7. Radix Sort
    std::cout << "Radix Sort\n";
    sort::RadixSort(A, 9);
    for(int i=0;i<9;i++){
      std::cout << A[i] << " ";
    }
    std::cout << '\n';

    return 0;
}