#include <iostream>

using namespace std;

bool check(string a, string b) {
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
    if (a_alphabet[i] != b_alphabet[i]) {
      return false;
    }
  }

  return true;
}

int main() {
  string a, b;
  int count = 1;

  while (true) {
    cin >> a >> b;

    if (a == "END" && b == "END") break;

    if (check(a, b))
      printf("Case %d: same\n", count);
    else
      printf("Case %d: different\n", count);

    count++;
  }
}