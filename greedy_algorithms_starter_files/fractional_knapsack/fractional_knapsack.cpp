#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

/*
  The value, weight and value per weight of a knapsack item change TOGETHER.
  Hence, all three values must be encapsulated in a single data structure.
  In particular, they will be sorted together according to value per weight.
  We don't need a fancy class for this; a simple, shitty, all-public,
  method-less struct is enough. Again, all we need to ensure is that the
  sort happens for all encapsulated data TOGETHER
*/
struct knapsack_item {
    long v;
    long w;
    double vperw;
};

double get_optimal_value(long capacity, vector<long> weights, vector<long> values) {
  const long n = weights.size();
  vector<knapsack_item> items(n);
  for (long i = 0; i < n; i++) {
    items[i].v = values[i];
    items[i].w = weights[i];
    if (weights[i] != 0) {
        items[i].vperw = values[i] / (double)weights[i];
    } else {
        items[i].vperw = 0.0;
    }
  }

  // sorts in descending order using a custom lambda function
  sort(items.begin(), items.end(), [](knapsack_item a, knapsack_item b) {
        return b.vperw < a.vperw;
    });

  double value = 0.0;
  for (long i = 0; i < n && capacity > 0; i++) {
      long a = (items[i].w < capacity)? items[i].w : capacity;
      value += a * items[i].vperw;
      capacity -= a;
  }

  return value;
}

int main() {
  long n;
  long capacity;
  std::cin >> n >> capacity;
  vector<long> values(n);
  vector<long> weights(n);
  for (long i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
