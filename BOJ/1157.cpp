#include <iostream>
#include <string>

using namespace std;

int main() {
  int* ALPHABET = new int[26];
  string S;
  int max = -987654321;
  int maxIndex = 0;
  bool hasManyMax = false;

  cin >> S;

  for (const auto& c : S) {
    ALPHABET[tolower(c) - 'a'] += 1;
  }

  for (int i = 0; i < 26; ++i) {
    if (ALPHABET[i] > max) {
      max = ALPHABET[i];
      maxIndex = i;
      hasManyMax = false;
    } else if (ALPHABET[i] == max) {
      hasManyMax = true;
    }
  }

  if (hasManyMax) {
    cout << '?' << '\n';
  } else {
    cout << char(maxIndex + 'A') << '\n';
  }

  return 0;
}