#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T, n;
  vector<int> numbers;

  cin >> T;

  while (T--) {
    numbers.clear();

    for (int i = 0; i < 10; i++) {
      cin >> n;
      numbers.push_back(n);
    }

    sort(numbers.begin(), numbers.end(), greater<>());

    cout << numbers[2] << '\n';
  }
}