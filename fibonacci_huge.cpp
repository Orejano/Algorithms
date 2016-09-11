#include <iostream>
/* This program will get the Nth Fibonacci number modulo m
 *  For this we uses the Pisano Period in order to work with smaller values */
 
// This is the naive function which uses brute forde NOT RECOMMENDED! 
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

// With this function we will get the pisano period, in order to work with smaller values
// of Fibonacci
// https://en.wikipedia.org/wiki/Pisano_period
long getPisanoPeriod(long long n, long long m) {
    int previous = 0;
    int current  = 1;
    int idx = 0;

    if (n <= 1) return n;

    if (m == 2) return 3;
    if (m == 3) return 8;

    for (idx = 0; idx < (m+n); ++idx) {
        int tmp_previous = previous;
        previous = current;
        current = (( tmp_previous % m )+ (current % m )) % m;
        if ( previous == 0 && current == 1) {
            break;
        }
    }
    return idx+1;
}

// Fast function using Pisano Period and Modulo to get the number we need
int get_fibonacci_huge_fast(long long n, long long m) {
    int previous = 0;
    int current  = 1;

    if (n <= 1)
        return n;

    int sup = n % getPisanoPeriod(n,m);

    if (sup==0) return 0;

    for (int i = 1; i < sup; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = ( tmp_previous % m + current % m );
    }

    return current%m;
}


int main() {
    long long n, m;
    std::cin >> n >> m;
//    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
