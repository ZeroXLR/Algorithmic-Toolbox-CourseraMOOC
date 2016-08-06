#include <iostream>

/* As n is at most 45, no need for a long long return type */
int calc_fib(int n) {
    if (n < 2)
        return n;

    int fib = 0, fibpre = 1, fibprepre = 0;
    for (int i = 1; i < n; i++, fibprepre = fibpre, fibpre = fib)
        fib = fibpre + fibprepre;

    return fib;
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << calc_fib(n) << '\n';
    return 0;
}
