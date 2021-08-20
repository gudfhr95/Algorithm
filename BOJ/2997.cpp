#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isArithemetic(vector<int> numbers, int n) {
  numbers.push_back(n);

  sort(numbers.begin(), numbers.end());

  int diff = numbers[1] - numbers[0];

  for (int i = 1; i < 3; i++) {
    if (numbers[i + 1] - numbers[i] != diff) return false;
  }

  return true;
}

int main() {
  int n;
  vector<int> numbers;
  vector<int> diffs;
  vector<int> candidates;

  for (int i = 0; i < 3; i++) {
    cin >> n;
    numbers.push_back(n);
  }

  sort(numbers.begin(), numbers.end());

  diffs.push_back(numbers[1] - numbers[0]);
  diffs.push_back(numbers[2] - numbers[1]);

  for (int i = 0; i < numbers.size(); i++) {
    for (int j = 0; j < diffs.size(); j++) {
      candidates.push_back(numbers[i] - diffs[j]);
      candidates.push_back(numbers[i] + diffs[j]);
    }
  }

  for (const auto &elem : candidates) {
    if (isArithemetic(numbers, elem)) {
      cout << elem;
      break;
    }
  }
}