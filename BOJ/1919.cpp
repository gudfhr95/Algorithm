#include <iostream>

using namespace std;

int main() {
  string a, b;
  int a_alphabet[26] = {
      0,
  };
  int b_alphabet[26] = {
      0,
  };

  cin >> a >> b;

  for (int i = 0; i < a.length(); i++) {
    a_alphabet[a[i] - 'a']++;
  }

  for (int i = 0; i < b.length(); i++) {
    b_alphabet[b[i] - 'a']++;
  }

  int result = 0;
  for (int i = 0; i < 26; i++) {
    result += abs(a_alphabet[i] - b_alphabet[i]);
  }

  cout << result;
}