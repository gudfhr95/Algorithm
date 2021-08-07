#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, n;
  vector<pair<int, int>> pairs;

  cin >> N;

  while (N--) {
    cin >> n;

    pairs.clear();

    for (int i = 1; i <= n / 2; i++) {
      if (i != n - i) pairs.push_back({i, n - i});
    }

    printf("Pairs for %d: ", n);

    for (int i = 0; i < pairs.size(); i++) {
      printf("%d %d", pairs[i].first, pairs[i].second);
      if (i != pairs.size() - 1) printf(", ");
    }

    printf("\n");
  }
}