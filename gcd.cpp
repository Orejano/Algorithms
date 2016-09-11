#include <iostream>

/* This program will get the GCD of two numbers
 * https://en.wikipedia.org/wiki/Greatest_common_divisor */
 
// This is the naive, brute force of getting the GCD (NOT RECOMMENDED!) 
int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}


// This is the smart, and fast way of getting GCD. It uses Euclidean Algorithm
// https://en.wikipedia.org/wiki/Euclidean_algorithm
long gcd_smart(long a, long b) {
    if ( a==0 || b == 0 ) return 0;
    if ( a==1 || b == 1 ) return 1;
    int r = 0;
    do {
        r = a % b;
        a = b;
        b = r;
    } while (b != 0);

   return a;
}

int main() {
  int a, b;
  std::cin >> a >> b;
//  std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_smart(a, b) << std::endl;
  return 0;
}
