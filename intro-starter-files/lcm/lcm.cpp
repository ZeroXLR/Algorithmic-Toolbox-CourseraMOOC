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

long long lcm(long a, long b) {
  //write your code here
  return a*(b / (long long)gcd(a, b));
}

int main() {
  long a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
