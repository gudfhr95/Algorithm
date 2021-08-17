#include <cstring>
#include <iostream>

using namespace std;

int ALPHABET[26];

int check_pangram() {
  int i;
  for (i = 1; i < 4; i++) {
    for (int j = 0; j < 26; j++) {
      if (ALPHABET[j] < i) return i - 1;
    }
  }
  return i - 1;
}

int main() {
  int n;
  string s;

  cin >> n;
  cin.ignore();

  for (int i = 1; i <= n; i++) {
    getline(cin, s);

    memset(ALPHABET, 0, sizeof(ALPHABET));

    for (int i = 0; i < s.length(); i++) {
      if (!isalpha(s[i])) continue;

      ALPHABET[tolower(s[i]) - 'a']++;
    }

    switch (check_pangram()) {
      case 0:
        printf("Case %d: Not a pangram\n", i);
        break;
      case 1:
        printf("Case %d: Pangram!\n", i);
        break;
      case 2:
        printf("Case %d: Double pangram!!\n", i);
        break;
      case 3:
        printf("Case %d: Triple pangram!!!\n", i);
        break;
    }
  }
}