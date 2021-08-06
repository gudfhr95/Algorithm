#include <iostream>
#include <string>

using namespace std;

bool isGroupWord(string S) {
  bool char_exists[26] = {
      false,
  };
  char_exists[S.at(0) - 'a'] = true;
  for (int i = 1; i < S.length(); ++i) {
    if (S.at(i) != S.at(i - 1)) {
      if (char_exists[S.at(i) - 'a']) {
        return false;
      } else {
        char_exists[S.at(i) - 'a'] = true;
      }
    }
  }
  return true;
}

int main() {
  int T;
  string S;

  int result = 0;

  cin >> T;

  for (int test_case = 0; test_case < T; ++test_case) {
    cin >> S;
    if (isGroupWord(S)) {
      result += 1;
    }
  }

  cout << result;

  return 0;
}