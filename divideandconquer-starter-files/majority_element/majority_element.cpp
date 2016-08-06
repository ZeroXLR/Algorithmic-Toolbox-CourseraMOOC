#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

typedef int canholdE5;
typedef long canholdE9;

using std::vector;
using std::cerr;
using std::endl;

canholdE9 gme_recurse(vector<canholdE9> &a, canholdE5 left, canholdE5 right) {
    if (left + 1 == right) return a[left];
    //write your code here
    canholdE5 halfdiff = (right - left) / 2;
    canholdE5 mid = left + halfdiff;

    canholdE9 lhalfres = gme_recurse(a, left, mid);
    canholdE9 rhalfres = gme_recurse(a, mid, right);

    if (lhalfres != -1) {// you proved yourself for half the array; now prove yourself for all of it!
        canholdE5 count = 0;
        for(canholdE5 i = left; i < right; i++)
            if(a[i] == lhalfres) count++;
        if(count > halfdiff) return lhalfres;
    }

    if (rhalfres != -1) {
        canholdE5 count = 0;
        for(canholdE5 i = left; i < right; i++)
            if(a[i] == rhalfres) count++;
        if(count > halfdiff) return rhalfres;
    }

    return -1;
}

inline canholdE9 get_majority_element(vector<canholdE9> &a, canholdE5 left, canholdE5 right) {
    return (left >= right)? -1 : gme_recurse(a, left, right);
}

canholdE9 brute_force_gme(vector<canholdE9> &a, canholdE5 left, canholdE5 right) {
    if(left >= right) return -1;
    for(canholdE5 i = left; i < right; i++) {
        canholdE5 count = 0;
        for(canholdE5 j = left; j < right; j++) {
            if(a[i] == a[j]) count++;
        }
        if(count > (right - left) / 2) return a[i];
    }
    return -1;
}

int main() {
  canholdE5 n; std::cin >> n;
  vector<canholdE9> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
  return 0;
  /*
  const long MAX_TEST_COUNT = 10000;
  const canholdE5 NUM_ELEM_CONTROL = 3;
  const canholdE9 MAX_VAL_CONTROL = 2;
  for (long i = 0; i < MAX_TEST_COUNT; i++) {
      canholdE9 n = ((canholdE9)rand()) % NUM_ELEM_CONTROL + 1;
      vector<canholdE9> a;
      for (canholdE5 i = 0; i < n; ++i) {
        a.push_back(((canholdE9)rand()) % MAX_VAL_CONTROL);
      }
      for (canholdE5 i = 0; i < n; ++i) {
        cerr << a[i] << ' ';
      }
      cerr << "\n";
      canholdE9 gmerec = get_majority_element(a, 0, a.size());
      canholdE9 gmebrute = brute_force_gme(a, 0, a.size());
      cerr << "gmerec:" << gmerec << " :: gmebrute:" << gmebrute << endl;
      assert(gmerec == gmebrute);
      cerr << "OK\n";
  }
  return 0;
  */
}
