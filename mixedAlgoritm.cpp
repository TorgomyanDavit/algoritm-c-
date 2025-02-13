#include <iostream>

// int fibonacci(int n) {
//     if(n < 2){return n;}

//     return fibonacci(n - 1) + fibonacci(n - 2);
// }

int fibonacci(int n) {
    if(n < 2){return n;}
    int current = 1,previous = 0;

    for(int i = 2;i < n;i++) {
        int temp = current + previous;
        previous = current;
        current = temp;
    }

    return current;
}

int main() {
    /** Array  exercize*/
    std::cout << "Sorting algoritm start" << std::endl;
    int arr[] = {2, 1, 3, 5, 4};
    int length = sizeof(arr) / sizeof(int);
    int resp = fibonacci(43);

    std::cout << resp << std::endl;
    return 0; 
}