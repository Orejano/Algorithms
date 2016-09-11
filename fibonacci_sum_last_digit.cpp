#include <iostream>
#include <math.h>

/* This programs sums up to the nth Fibonacci number and returns the last digit
 * 0 <= n <= 10^14 */

// Naive function NOT RECOMMENDED!
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

// SMART Function
int fibonacci_sum_smart(long long n) {
    if (n==0) return 0;
    if (n==1) return 1;
    if (n==2) return 2;
    if (n==3) return 4;

// Pisano period is used to get the final digit of the sum, which is periodic.
// https://en.wikipedia.org/wiki/Pisano_period	
    int pisano   = (n+2) % 60;

    if (pisano==0) return 0;

// This is Binet's formula, which will help us get the Nth Fibonacci number
// https://en.wikipedia.org/wiki/Jacques_Philippe_Marie_Binet	
    long binet = (long)((pow((1+sqrt(5)),pisano) - pow((1-+sqrt(5)),pisano)) /
                      (pow(2,pisano)*sqrt(5)));

// This is the sum of the Nth Fibonacci numbers. More on this on:
// https://en.wikipedia.org/wiki/Fibonacci_number
    int fn = (binet - 1) % 10;

    return fn;
}

int main() {
    long long n = 0;
    std::cin >> n;
//    std::cout << fibonacci_sum_naive(n);
    std::cout << fibonacci_sum_smart(n);

}
