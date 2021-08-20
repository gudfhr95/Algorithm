#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(string &a, string &b) {
  if (a.length() != b.length()) return a.length() < b.length();

  int sum_a = 0;
  int sum_b = 0;

  for (int i = 0; i < a.length(); i++) {
    if (isdigit(a[i])) sum_a += a[i] - '0';
    if (isdigit(b[i])) sum_b += b[i] - '0';
  }

  if (sum_a != sum_b) return sum_a < sum_b;

  return a < b;
}

int main() {
  int N;
  string s;
  vector<string> serial;

  cin >> N;

  while (N--) {
    cin >> s;
    serial.push_back(s);
  }

  sort(serial.begin(), serial.end(), cmp);

  for (const auto &elem : serial) {
    cout << elem << '\n';
  }
}