#include <iostream>

using namespace std;

int main() {
  int n;
  string s;

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> s;

    printf("String #%d\n", i);

    for (int i = 0; i < s.length(); i++) {
      cout << (char)((((s[i] - 'A') + 1) % 26) + 'A');
    }

    cout << "\n\n";
  }
}