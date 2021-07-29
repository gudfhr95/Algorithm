#include <iostream>

using namespace std;

int main() {
  int T, R;
  string S;
  string result;

  cin >> T;

  while (T--) {
    cin >> R >> S;

    result = "";
    for (int i = 0; i < S.length(); i++) {
      for (int j = 0; j < R; j++) {
        result += S[i];
      }
    }

    cout << result << '\n';
  }
}