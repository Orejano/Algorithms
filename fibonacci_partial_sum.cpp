#include <iostream>
#include <math.h>
#include <vector>
using std::vector;

/* This programs calculate the sum of two fibonacci numbers where 0 <= n <= m <= 10^18
 * SUM = F(n) + F(n+1) + ... + F(m)
 * The naive function uses brute force (NOT RECOMMENDED!)
 * The fast function uses Binet' Formula */

/* This is the naive option to get the partial sum of two Fibonacci numbers */
long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

/* This function get the Nth Fibonacci number using Binet's formula */
long long binet(long long n) {
    if (n==0) return 0;

// We use pisano period to reduce the number of the Nth Fibonacci term. Last digit of a fibonacci
// serie has a periodicty of 60.
// https://en.wikipedia.org/wiki/Pisano_period
// http://webspace.ship.edu/msrenault/fibonacci/fiblist.htm

    int pisano   = (n+2) % 60;

    long long binet = (long long)((pow((1+sqrt(5)),pisano) - pow((1-sqrt(5)),pisano)) /
                        (pow(2,pisano)*sqrt(5)));

    long long fn = (binet - 1);

    return fn;

}

/* This is the fast function, it uses Binet's formula
 * (https://en.wikipedia.org/wiki/Jacques_Philippe_Marie_Binet)
 */
int get_fibonacci_partial_sum_smart(long long from, long long to) {

    long long l_from = binet(from-1);
    long long l_to = binet(to);

    return (l_to - l_from) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
//    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_smart(from, to) << '\n';
}
