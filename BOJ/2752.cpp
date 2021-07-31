#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<int> numbers;

  for (int i = 0; i < 3; i++) {
    cin >> n;
    numbers.push_back(n);
  }

  sort(numbers.begin(), numbers.end());

  for (const auto &elem : numbers) {
    cout << elem << ' ';
  }
}