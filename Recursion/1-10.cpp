#include <iostream>
#include <vector>
#include <string>

//1.
int factorial(int num){
    if(num==0){
        return 1;
    }
    else{
        return num*factorial(num-1);
    }
}

//2.
int power(int a,int n){
    if(n==0){
        return 1; 
    }
    else{
        int x=power(a,n/2);
        if(n%2==0){
            return x*x;
        }
        else{
            return a*x*x;
        }
    }
}

//3.
int fibonacci(int n){
    if(n<=2){
        return n-1;
    }
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

//4.
int gcd(int a, int b){
    if(b==0){
        return 0;
    }
    else{
        return gcd(b,a%b);
    }
}

//5.
int binarySearch(std::vector<int> &arr,int left,int right,int target) {
    if(left>right){
        return -1;
    } 
    int mid=left+((right-left)/2);
    if (arr[mid] == target){
        return mid;
    }
    if (arr[mid] > target){
        return binarySearch(arr,left,mid-1,target);
    } 
    else{
        return binarySearch(arr,left,mid+1,target);
    }
        
}

//6.
void Hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 0) return;
    Hanoi(n - 1, source, destination, auxiliary);
    std::cout << "Move disk " << n << " from " << source << " to " << destination << "\n";
    Hanoi(n - 1, auxiliary, source, destination);
}

//7.
int reverseHelper(int n, int rev) {
    if (n == 0)
        return rev;
    return reverseHelper(n / 10, rev * 10 + n % 10);
}

int reverse(int n) {
    return reverseHelper(n, 0);
}

//8.
int digitsum(int n){
    if(n==0){
        return 0;
    }
    else{
        return n%10+digitsum(n/10);
    }
}

//9.
bool palindrome(std::string s,int i, int j){
    if(i<j && s[i] == s[j]){
        return palindrome(s,i+1,j-1);
    }
    else if(i<j && s[i]!=s[j]){
        return false;
    }
    else if(i>=j){
        return true;
    }
}

//10.
int elemsum(std::vector<int> &arr,int n){
    if(n==0){
        return arr[0];
    }
    else{
        return arr[n]+elemsum(arr,n-1);
    }
}

int main(){
    int fact{};
    std::cout << "Enter number to find factorial: ";
    std::cin >> fact;
    std::cout << fact << "! = " << factorial(fact) << '\n';

    int base{},exp{};
    std::cout << "Enter base and Exponent repectively: ";
    std::cin >> base >> exp;
    std::cout << base << '^' << exp << " = " << power(base,exp) << '\n';
    
    int fib{};
    std::cout << "Enter term of fibonacci series: ";
    std::cin >> fib;
    std::cout << fib << "term of the series is: " << fibonacci(fib) << '\n'; 

    int gcd1{},gcd2{};
    std::cout << "Enter Two numbers to find thier gcd: ";
    std::cin >> gcd1 >> gcd2;
    std::cout << "gcd of " << gcd1 << " and " << gcd2 << " = " << gcd(gcd1,gcd2) << '\n';

    std::vector <int> bin={1,2,3,4,5,6,7,8,9,10};
    int elem{};
    std::cout << "Enter element to find usng binary search: ";
    int pos{binarySearch(bin,0,bin.size(),elem)};
    if(pos == -1){
        std::cout << "Element not found\n";
    }
    else{
        std::cout << "Element found at " << pos << '\n';
    }

    int num{};
    std::cout << "enter number to reverse: ";
    std::cin >> num;
    std::cout << "Reversed number: " << reverse(num);

    int disks{};
    std::cout << "Enter number of disks: ";
    std::cin >> disks;
    Hanoi(disks, 'A', 'B', 'C');
    std::cout << '\n';

    int sum{};
    std::cout << "Enter number to find the sum of its digits: ";
    std::cin >> sum;
    std::cout << "Sum of digits: " << digitsum(sum) << '\n';

    std::string s;
    std::cout << "Enter a string to check if it is palindrome or not: ";
    std::cin >> s;
    std::cout << palindrome(s,0,s.length())?"Yes\n" : "No\n";

    std::cout << "Enter size of array: ";
    int size{};
    std::vector <int> arr(size);
    std::cout << "Enter elements: ";
    for(int i=0;i<size;i++){
        std::cin >> arr[i];
    }
    std::cout << "Sum of elements: " << elemsum(arr,size-1);

    return 0;
}