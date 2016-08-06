#include <iostream>
#include <vector>

using std::vector;

struct GhettoMatrix {
    long** matrix;
    GhettoMatrix(size_t r, size_t c) {
        if (r < 1 || c < 1) {
            matrix = nullptr;
        } else {
            this->r = r; this->c = c;
            matrix = new long*[r];
            for (size_t i = 0; i < r; ++i) {
                matrix[i] = new long[c];
                matrix[i][0] = 0; // initialize zeroth column
            }
            for (size_t i = 0; i < c; ++i) matrix[0][i] = 0;  // initialize zeroth row
        }
    }
    ~GhettoMatrix() {
        for (size_t i = 0; i < r; ++i) delete [] matrix[i];
        delete [] matrix;
    }
    private:
        size_t r, c;
};

inline void bound_check(const long W, const vector<long> &w) {
    if (W < 1 || W > 10000 || w.size() < 1 || w.size() > 300)
        throw std::out_of_range("W or w.size() out of range"); // die on bad input
    for (size_t i = 0; i < w.size(); ++i)
        if (w[i] < 0 || w[i] > 100000) throw std::out_of_range("a wi is out of range"); // die on bad input
}

long optimal_dynamic_weight(long W, const vector<long> &w) {
    bound_check(W, w);

    const size_t rCount = w.size()+1;
    const size_t cCount = W+1;
    GhettoMatrix MGM(rCount, cCount);
    long** MaxGoldMat = MGM.matrix;

    for (size_t i = 1, imin1 = 0; i < rCount; imin1 = i, ++i) {
        // remember, the matrix has 1 more than w.size() so, currw = w[imin1]
        long prev_no_wi, prev_with_wi, currw = w[imin1], *row_above = MaxGoldMat[imin1];
        for (size_t currW = 1; currW < cCount; ++currW) {
            prev_no_wi = row_above[currW];
            MaxGoldMat[i][currW] = (currw > currW ||
                (prev_with_wi = row_above[currW-currw] + currw) <= prev_no_wi)?
                    prev_no_wi : prev_with_wi;
        }
    } long max_weight = MaxGoldMat[w.size()][W];

    return max_weight;
}

long suboptimal_greedy_weight(long W, const vector<long> &w) {
  //write your code here
  long current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int main() {
  size_t n; long W;
  std::cin >> W >> n;
  vector<long> w(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_dynamic_weight(W, w) << '\n';
  return 0;
}
