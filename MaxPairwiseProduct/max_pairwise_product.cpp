#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::cerr;

long long MaxPairwiseProduct(const vector<int>& numbers) {
  /* To prevent int-multiplication overflows, a long long
  result is used to catch the output */
  long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (((long long)numbers[i]) * numbers[j] > result) {
        result = ((long long)numbers[i]) * numbers[j];
      }
    }
  }
  return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {
  int n = numbers.size();

  int max_index1 = -1;
  for (int i = 0; i < n; ++i)
    if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
      max_index1 = i;

  int max_index2 = -1;
  for (int j = 0; j < n; ++j)
    if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
      max_index2 = j;

  return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main() {
    /* Stress test:
    const long long MAX_TEST_COUNT = 100000; // 100000 test cases at max!
    for (long long count = 0; count < MAX_TEST_COUNT; count++) {
      int n = rand() % 10 + 2;
      cerr << n << "\n";
      vector<int> a;
      for (int i = 0; i < n; ++i) {
        a.push_back(rand() % 100000);
      }
      for (int i = 0; i < n; ++i) {
        cerr << a[i] << ' ';
      }
      cerr << "\n";
      long long res1 = MaxPairwiseProduct(a);
      long long res2 = MaxPairwiseProductFast(a);
      if (res1 != res2) {
        cerr << "Wrong answer: " << res1 << ' ' << res2 << "\n";
        break;
      }
      else {
        cerr << "OK\n";
      }
    }
    */
    /* For actual submission: */
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProductFast(numbers);
    cout << result << "\n";
    return 0;
}
