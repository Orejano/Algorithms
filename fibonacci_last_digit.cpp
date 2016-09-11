#include <iostream>

/* This program will get the last digit of the Nth Fibonacci number
 * It uses modulo properties to make it fast and simple */
 
// This is the naive, brute force of getting the last digit (NOT RECOMMENDED!)
int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

// This function will get the last digit of the Nth Fibonacci number using modulo properties
// https://en.wikipedia.org/wiki/Modular_arithmetic
int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous % 10) + (current % 10);
    }

    return current % 10;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
//    c = get_fibonacci_last_digit_naive(n);
//    std::cout << c << '\n';

    }
