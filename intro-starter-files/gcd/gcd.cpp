#include <iostream>

void right_order(long &a, long &b) {
    if (a < b) {
        long temp = a;
        a = b;
        b = temp;
    }
}

long gcd(long a, long b) {
  right_order(a, b);

  if (b == 0) return a;

  return gcd(b, a % b);
}

int main() {
  long a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
