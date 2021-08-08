#include <iostream>
#include <map>

using namespace std;

int main() {
  int N, M, count = 0;
  string s;
  map<string, int> peoples;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> s;
    peoples[s]++;
  }

  for (int j = 0; j < M; j++) {
    cin >> s;
    peoples[s]++;
  }

  for (const auto &elem : peoples) {
    if (elem.second == 2) count++;
  }

  cout << count << '\n';

  for (const auto &elem : peoples) {
    if (elem.second == 2) cout << elem.first << '\n';
  }
}