#include <iostream>
#include <cstdlib>

int get_change(int n) {
  /*
     Greedily choose the largest denomination <= n
     and subtract it from n; continue with the new
     reduced value of n. This is a safe move. For:
     suppose d1 >= ... >= ds are the denominations
     summing upto n that we successively got by
     applying our greed choices. Now, since n is
     finite and always decomposable, at the very
     least into 1s, an optimal choice must exist by
     the well-ordering principle of the naturals. Let
     dd1 >= ... >= ddt be such a decomposition. Both
     series sum to n. So, if they differ, there has to
     be an index 1 <= i <= t,s of difference. WLOG, let
     i be the first such index. Then, necessarily,
     since our greedy strategy always chooses the
     greatest possible denomination less than the
     remaining value from n, ddi < di. If di = 5, then
     ddi = 1 and all the ddj's for j less than i upto
     t must be 1s too according to our ordering. Also,
     all the dj's must be 1s too (otherwise, our greedy
     strategy would have chosen di = 10). Thus, the dd
     series must have di - ddi = 4 more 1s in the
     decomposition than the d series, violating its
     optimality. If di = 10, then ddi = 1 or 5. The
     argument is only slightly more involved in this
     case but the same violation of optimality follows.
  */
  int count = 0;
  while (n > 0)
      if (n >= 10) {
          div_t ndiv10 = div(n, 10);
          count += ndiv10.quot;
          n = ndiv10.rem;
          //count += n/10;
          //n %= 10;
      } else if (n >= 5) {
          div_t ndiv5 = div(n, 5);
          count += ndiv5.quot;
          n = ndiv5.rem;
          //count += n/5;
          //n %= 5;
      } else {
          count += n;
          n = 0;
      }
  return count;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
