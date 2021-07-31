#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, n;
  vector<int> numbers;

  cin >> N;

  while (N--) {
    cin >> n;
    numbers.push_back(n);
  }

  sort(numbers.begin(), numbers.end());

  for (const auto &elem : numbers) {
    cout << elem << '\n';
  }
}