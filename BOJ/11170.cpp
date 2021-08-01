#include <iostream>

using namespace std;

int countZeros(int n) {
  int result = 0;

  string s = to_string(n);

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0') result++;
  }

  return result;
}

int main() {
  int T, N, M, result;

  cin >> T;

  while (T--) {
    cin >> N >> M;

    result = 0;

    for (int i = N; i <= M; i++) {
      result += countZeros(i);
    }

    cout << result << '\n';
  }
}