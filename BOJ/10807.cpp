#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, n, v, result = 0;
  vector<int> numbers;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> n;
    numbers.push_back(n);
  }

  cin >> v;

  for (const auto &elem : numbers) {
    if (elem == v) result++;
  }

  cout << result;
}