#include <iostream>

using namespace std;

bool isAnagram(string a, string b) {
  int a_alphabet[26] = {
      0,
  };
  int b_alphabet[26] = {
      0,
  };

  for (int i = 0; i < a.length(); i++) {
    a_alphabet[a[i] - 'a']++;
  }

  for (int i = 0; i < b.length(); i++) {
    b_alphabet[b[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (a_alphabet[i] != b_alphabet[i]) return false;
  }

  return true;
}

int main() {
  int T;
  string a, b;

  cin >> T;

  while (T--) {
    cin >> a >> b;

    if (isAnagram(a, b))
      printf("%s & %s are anagrams.\n", a.c_str(), b.c_str());
    else
      printf("%s & %s are NOT anagrams.\n", a.c_str(), b.c_str());
  }
}