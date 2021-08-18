#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, P;

  while (true) {
    cin >> N;

    if (N == 0) break;

    cin >> P;

    vector<vector<int>> pages;
    for (int i = 1; i <= N / 4; i++) {
      vector<int> page = {(2 * i) - 1, 2 * i, N - (2 * i) + 1, N - (2 * i) + 2};
      pages.push_back(page);
    }

    for (int i = 0; i < pages.size(); i++) {
      for (int j = 0; j < 4; j++) {
        if (pages[i][j] == P) {
          for (int k = 0; k < 4; k++) {
            if (k == j) continue;
            cout << pages[i][k] << ' ';
          }
        }
      }
    }

    cout << '\n';
  }
}