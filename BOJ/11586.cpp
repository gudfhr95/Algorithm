#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  string s;
  vector<string> mirror;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> s;
    mirror.push_back(s);
  }

  cin >> K;

  if (K == 2) {
    for (int i = 0; i < mirror.size(); i++) {
      reverse(mirror[i].begin(), mirror[i].end());
    }
  } else if (K == 3) {
    reverse(mirror.begin(), mirror.end());
  }

  for (const auto &elem : mirror) {
    cout << elem << '\n';
  }
}