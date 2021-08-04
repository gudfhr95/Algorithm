#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(string &a, string &b) {
  if (a.length() != b.length())
    return a.length() < b.length();
  else
    return a < b;
}

int main() {
  int N;
  string s;
  vector<string> l;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> s;
    if (find(l.begin(), l.end(), s) == l.end()) l.push_back(s);
  }

  sort(l.begin(), l.end(), cmp);

  for (const auto &elem : l) {
    cout << elem << '\n';
  }
}