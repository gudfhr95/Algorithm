#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int K;
  string s;
  vector<string> v;

  cin >> K >> s;

  for (int i = 0; i < s.length() / K; i++) {
    string substring = s.substr(i * K, K);

    if (i % 2 == 1) reverse(substring.begin(), substring.end());

    v.push_back(substring);
  }

  for (int x = 0; x < K; x++) {
    for (int y = 0; y < v.size(); y++) {
      cout << v[y][x];
    }
  }
}
