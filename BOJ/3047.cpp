#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  string s;
  vector<int> numbers;

  for (int i = 0; i < 3; i++) {
    cin >> n;
    numbers.push_back(n);
  }

  sort(numbers.begin(), numbers.end());

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    cout << numbers[s[i] - 'A'] << ' ';
  }
}