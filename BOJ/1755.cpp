#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string NUMBER[10] = {"zero", "one", "two",   "three", "four",
                     "five", "six", "seven", "eight", "nine"};

string toString(int n) {
  string result;

  if (n < 10) {
    result = NUMBER[n];
  } else {
    result = NUMBER[n / 10] + ' ' + NUMBER[n % 10];
  }

  return result;
}

int main() {
  int M, N;
  vector<pair<string, int>> numbers;

  cin >> M >> N;

  for (int i = M; i <= N; i++) {
    numbers.push_back({toString(i), i});
  }

  sort(numbers.begin(), numbers.end());

  for (int i = 0; i < numbers.size(); i++) {
    cout << numbers[i].second << ' ';

    if (i % 10 == 9) {
      cout << '\n';
    }
  }
}
