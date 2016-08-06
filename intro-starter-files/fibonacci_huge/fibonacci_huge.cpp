#include <iostream>

long long Fmodm(long long n, long long m) {
    if (n < 2)
        return n;

    long long fib = 0;
    for (long long i = 1, fibpre = 1, fibprepre = 0;
         i < n; i++, fibprepre = fibpre, fibpre = fib)
        fib = (fibpre + fibprepre) % m;

    return fib;
}

long long get_fibonaccihuge(long long n, long long m) {
  /* We need to find the Pisano period by noticing that
     the sequence will eventually output a 0 and a 1
     again (the proof BEGINS by noting that any function
     f:X->S over a finite subset S of X, iterated over
     any s in S, is eventually periodic ... here,
     X = {0 1 ... }, S = {0 ... m}, Fmodm(0) = 0,
     Fmodm(1) = 1, Fmodm(n) = Fmodm(n-1) +@m Fmodm(n-2)).
     Since the next Fibonacci number only depends on the
     last two values, reproducing the two intial values 0
     and 1 guarantees the sequence begins anew. So, to
     find the Pisano period, we need to run the Fmodm
     algorithm until a 0 and a 1 are encountered in
     consecution.
  */
  long long pisano = 1;
  for (long long fibpre = 1, fibprepre = 0, fib = (fibpre + fibprepre) % m;
       fib != 1 || fibpre != 0;
       fibprepre = fibpre, fibpre = fib, fib = (fibpre + fibprepre) % m,
       pisano++);

  return Fmodm(n % pisano, m);
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonaccihuge(n, m) << '\n';
}
