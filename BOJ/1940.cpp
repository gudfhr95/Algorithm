#include <iostream>
#include <map>

using namespace std;

int main() {
  int N, M, n, result = 0;
  map<int, int> materials;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> n;
    materials[n]++;
  }

  for (int i = 1; i <= M / 2; i++) {
    if (i == M - i) {
      result += materials[i] / 2;
    } else {
      result += min(materials[i], materials[M - i]);
    }
  }

  cout << result;
}