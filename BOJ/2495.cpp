#include <iostream>

using namespace std;

int count(string s) {
  int max_count = 0, temp_count = 1;

  char c = s[0];
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == c)
      temp_count++;
    else {
      c = s[i];
      max_count = max(max_count, temp_count);
      temp_count = 1;
    }
  }
  max_count = max(max_count, temp_count);

  return max_count;
}

int main() {
  string s;

  for (int i = 0; i < 3; i++) {
    cin >> s;

    cout << count(s) << '\n';
  }
}