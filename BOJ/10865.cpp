#include <iostream>

using namespace std;

int main() {
  int N, M, a, b;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  int friends[100001] = {
      0,
  };

  while (M--) {
    cin >> a >> b;

    friends[a]++;
    friends[b]++;
  }

  for (int i = 1; i <= N; i++) {
    cout << friends[i] << '\n';
  }
}