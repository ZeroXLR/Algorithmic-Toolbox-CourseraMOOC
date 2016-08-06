#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>

typedef long ELEMENT;

using std::vector;
using std::ldiv;
using std::ldiv_t;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

vector<ELEMENT> optimal_dynamic_sequence(ELEMENT n) {
    if (n < 1 || n > 1000000) throw std::out_of_range("n out of range"); // die on bad input

    vector<ELEMENT> sequence;
    vector<ELEMENT> min_seqs(n+1); // n+1 size for nice indexing: the optimal value for x is stored at min_seqs[x]
    min_seqs[0] = 0; // padding; unused value to allow nice indexing
    min_seqs[1] = 0; // first actual entry

    for (ELEMENT seqelem = 2; seqelem < min_seqs.size(); ++seqelem) {
        ELEMENT &val_seqelem = min_seqs[seqelem];

        ldiv_t seqelem_by_2 = ldiv(seqelem, 2);
        ldiv_t seqelem_by_3 = ldiv(seqelem, 3);

        val_seqelem = min_seqs[seqelem - 1]; // default initialization since you can always get to current element from previous element by adding 1
        if (seqelem_by_3.rem == 0 && min_seqs[seqelem_by_3.quot] < val_seqelem)
            val_seqelem = min_seqs[seqelem_by_3.quot];
        if (seqelem_by_2.rem == 0 && min_seqs[seqelem_by_2.quot] < val_seqelem)
            val_seqelem = min_seqs[seqelem_by_2.quot];

        ++val_seqelem;
    }

    while (n >= 1) {
        sequence.push_back(n);
        ldiv_t n_by_2 = ldiv(n, 2);
        ldiv_t n_by_3 = ldiv(n, 3);
        if (n_by_3.rem == 0 && min_seqs[n_by_3.quot]+1 == min_seqs[n]) n = n_by_3.quot;
        else if (n_by_2.rem == 0 && min_seqs[n_by_2.quot]+1 == min_seqs[n]) n = n_by_2.quot;
        else --n;
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

// This greedy algorithm fails for at least n = 10!
vector<ELEMENT> suboptimal_greedy_sequence(ELEMENT n) {
  vector<ELEMENT> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  ELEMENT n;
  cin >> n;
  vector<ELEMENT> sequence = optimal_dynamic_sequence(n);
  cout << sequence.size() - 1 << endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    cout << sequence[i] << " ";
  } cout << endl;
}
