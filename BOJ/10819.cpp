#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, n, result = -987654321;
  vector<int> numbers;

  cin >> N;

  while (N--) {
    cin >> n;
    numbers.push_back(n);
  }

  sort(numbers.begin(), numbers.end());

  do {
    int sum = 0;
    for (int i = 0; i < numbers.size() - 1; i++) {
      sum += abs(numbers[i] - numbers[i + 1]);
    }
    result = max(result, sum);
  } while (next_permutation(numbers.begin(), numbers.end()));

  cout << result;
}
