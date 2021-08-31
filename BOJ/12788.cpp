#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M, K, A;
  vector<int> pens;

  cin >> N >> M >> K;

  while (N--) {
    cin >> A;
    pens.push_back(A);
  }

  sort(pens.begin(), pens.end(), greater<>());

  int total = M * K;
  for (int i = 0; i < pens.size(); i++) {
    total -= pens[i];

    if (total <= 0) {
      cout << i + 1;
      return 0;
    }
  }

  cout << "STRESS";
}