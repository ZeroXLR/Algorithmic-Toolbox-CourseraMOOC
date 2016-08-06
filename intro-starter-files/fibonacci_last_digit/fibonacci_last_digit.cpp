#include <iostream>

int get_fibonacci_last_digit(long n) {
    if (n < 2)
        return (int)n;

    int fib = 0, fibpre = 1, fibprepre = 0;
    for (long i = 1; i < n; i++, fibprepre = fibpre, fibpre = fib)
        fib = (fibpre + fibprepre) % 10;

    return fib;

}

int main() {
  long n;
  std::cin >> n;
  int c = get_fibonacci_last_digit(n);
  std::cout << c << '\n';
}
