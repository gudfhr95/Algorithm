#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, n;
  vector<int> numbers;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> n;
    numbers.push_back(n);
  }

  if (!next_permutation(numbers.begin(), numbers.end())) {
    cout << -1;
  } else {
    for (const auto &elem : numbers) {
      cout << elem << ' ';
    }
  }
}
