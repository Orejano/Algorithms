#include <iostream>

/* This program will return the LCM (large common multiple) */

// This is the naive, brute force of getting the LCM (NOT RECCOMMENDED)
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_smart(int a, int b) {
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

// This is the smart fast way of getting the LCM. For this we uses the GCD
// based on the following equation: LCM(a,b) = (a*b)/GCD(a,b)
long long lcm_smart(long long a, long long b) {
    if ( a==0 || b==0) return 0;

    int gcd = gcd_smart(a,b);

    return a/gcd*b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_smart(a, b) << std::endl;
//  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}