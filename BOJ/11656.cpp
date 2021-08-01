#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s;
  vector<string> prefixes;

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    prefixes.push_back(s.substr(i, s.length()));
  }

  sort(prefixes.begin(), prefixes.end());

  for (const auto &elem : prefixes) {
    cout << elem << '\n';
  }
}