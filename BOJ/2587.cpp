#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, sum = 0;
  vector<int> numbers;

  for (int i = 0; i < 5; i++) {
    cin >> n;

    sum += n;
    numbers.push_back(n);
  }

  sort(numbers.begin(), numbers.end());

  cout << sum / 5 << '\n' << numbers[2];
}