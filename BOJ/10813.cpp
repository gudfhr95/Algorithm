#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M, i, j, temp;
  vector<int> basket;

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    basket.push_back(i);
  }

  while (M--) {
    cin >> i >> j;
    temp = basket[i - 1];
    basket[i - 1] = basket[j - 1];
    basket[j - 1] = temp;
  }

  for (const auto &elem : basket) {
    cout << elem << ' ';
  }
}