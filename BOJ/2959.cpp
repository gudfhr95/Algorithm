#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  vector<int> numbers;

  for (int i = 0; i < 4; i++) {
    cin >> N;
    numbers.push_back(N);
  }

  sort(numbers.begin(), numbers.end());

  cout << numbers[0] * numbers[2];
}