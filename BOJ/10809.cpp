#include <iostream>

using namespace std;

int RESULT[26];

int main() {
  string S;
  int index;

  cin >> S;

  for (int i = 0; i < 26; ++i) {
    RESULT[i] = -1;
  }

  for (int i = 0; i < S.length(); ++i) {
    index = S.at(i) - 'a';
    if (RESULT[index] == -1) {
      RESULT[index] = i;
    }
  }

  for (int i = 0; i < 26; ++i) {
    cout << RESULT[i] << " ";
  }

  return 0;
}