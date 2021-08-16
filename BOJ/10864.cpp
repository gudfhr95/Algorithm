#include <iostream>
#include <map>

using namespace std;

int main() {
  int N, M, a, b;
  map<int, int> friends;

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    friends[i] = 0;
  }

  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    friends[a]++;
    friends[b]++;
  }

  for (const auto &elem : friends) {
    cout << elem.second << '\n';
  }
}
