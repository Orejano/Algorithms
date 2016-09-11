#include <iostream>
#include <cassert>

//This simple program computes the Nth Fibonacci number

// The following code calls a naive algorithm for computing a Fibonacci number.
int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

//Fast way of getting the Fibonacci number
int fibonacci_fast(int n) {
    int fibo[n];
    fibo[0]=0;
    fibo[1]=1;
    for (int i = 2; i <= n; ++i) {
        fibo[i]= fibo[i-1]+fibo[i-2];
    }
    return fibo[n];
}

int main() {
    int n = 0;
    std::cin >> n;

//    std::cout << fibonacci_naive(n) << '\n';
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
