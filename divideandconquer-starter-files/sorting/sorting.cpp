#include <iostream>
#include <vector>

typedef int INDEX;
typedef long ELEMENT;

using std::vector;
using std::swap;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

typedef struct {
    INDEX head;
    INDEX tail;
} EQS_REG;

EQS_REG partition3(vector<ELEMENT> &a, INDEX l, INDEX r) {
  ELEMENT x = a[l];
  INDEX j = l; // INDEX of the head of equals-region
  INDEX k = l; // INDEX of the tail of equals-region
  {
      INDEX i = l + 1; // iterator with scope across both loops
      for (; i <= r && a[i] != x; i++)
        if (a[i] < x) {
          j++; k++;
          swap(a[i], a[j]); // no need to worry about less-than-region spilling into equals-region YET
        }

      for (; i <= r; i++)
        if (a[i] == x) {
          k++;
          swap(a[i], a[k]);
        } else if (a[i] < x) {
          j++; k++;
          swap(a[i], a[j]); // head of equals-region just got swapped while expanding less-than-region! BAD!
          swap(a[i], a[k]); // fix it by swapping in the displaced equals-region ELEMENT, now at a[i], to the region's tail-end
        }
  }
  swap(a[l], a[j]);
  EQS_REG res = {.head = j, .tail = k};
  return res;
}

void randomized_quick_sort(vector<ELEMENT> &a, INDEX l, INDEX r) {
  // while-loop to eliminate one of the tail recursive calls
  while (r > l) {

    INDEX k = l + rand() % (r - l + 1); // choose a random pivot within range
    swap(a[l], a[k]); // send the pivot to the front

    EQS_REG m = partition3(a, l, r); // get the head and tail locations of the equals-region

    // choose the recursion with the smaller number of elements to sort
    if (m.head - l < r - m.tail) {
        randomized_quick_sort(a, l, m.head - 1);
        l = m.tail + 1;
    } else {
        randomized_quick_sort(a, m.tail + 1, r);
        r = m.head - 1;
    }

  }
}

int main() {
  INDEX n;
  cin >> n;
  vector<ELEMENT> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';
  }
  cout << endl;
  return 0;
  /*
  vector<ELEMENT> a(10000000); // stress test the sort on a million identical elements
  for (size_t i = 0; i < a.size(); ++i) {
    a[i] = 42;
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  return 0;
  */
}
