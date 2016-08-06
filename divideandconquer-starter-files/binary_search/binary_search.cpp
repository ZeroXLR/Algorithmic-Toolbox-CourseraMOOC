#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using std::sort;
using std::vector;
using std::cerr;
using std::endl;

long binary_search(const vector<long> &a, const long x) {
  long left = 0, right = (long)(a.size()-1);
  //write your code here
  while (left <= right) {
    long mid = left + (right - left)/2;
    if (a[mid] < x)
        left = mid + 1;
    else if (a[mid] > x)
        right = mid - 1;
    else
        return mid;
  }
  return -1;
}

long linear_search(const vector<long> &a, const long x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  /*
  const long MAX_TEST_COUNT = 10000;
  const long NUM_ELEM_CONTROL = 100;
  const long MAX_VAL_CONTROL = 10;
  for (long i = 0; i < MAX_TEST_COUNT; i++) {
      int n = rand() % NUM_ELEM_CONTROL + 2;
      cerr << n << "\n";
      vector<long> a;
      for (int i = 0; i < n; ++i) {
        a.push_back(((long)rand()) % MAX_VAL_CONTROL);
      }
      sort(a.begin(), a.end());
      for (int i = 0; i < n; ++i) {
        cerr << a[i] << ' ';
      }
      cerr << "\n";
      long x = ((long)rand()) % MAX_VAL_CONTROL;
      cerr << "x: " << x << endl;
      long bs = binary_search(a, x);
      long ls = linear_search(a, x);
      cerr << "bs:" << bs << " :: ls:" << ls << endl;
      cerr << "check: either bs and ls both -1 or a[bs] == a[ls]" << endl;
      assert((bs == -1 && ls == -1) || a[bs] == b[ls]);
      cerr << "OK\n";
  }
  return 0;
  */
  /**/
  long n;
  std::cin >> n;
  vector<long> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  long m;
  std::cin >> m;
  vector<long> b(m);
  for (long i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (long i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
  std::cout << std::endl;
  return 0;
  /**/
}
