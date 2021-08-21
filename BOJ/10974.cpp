#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<int> numbers;

  cin >> n;

  for (int i = 1; i <= n; i++) {
    numbers.push_back(i);
  }

  do {
    for (auto it = numbers.begin(); it != numbers.end(); it++) {
      cout << *it << ' ';
    }
    cout << '\n';
  } while (next_permutation(numbers.begin(), numbers.end()));
}
