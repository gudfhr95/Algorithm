#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string s;
  int cups[3] = {1, 0, 0};

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    switch (s[i]) {
      case 'A':
        swap(cups[0], cups[1]);
        break;
      case 'B':
        swap(cups[1], cups[2]);
        break;
      case 'C':
        swap(cups[0], cups[2]);
        break;
    }
  }

  for (int i = 0; i < 3; i++) {
    if (cups[i] == 1) {
      cout << i + 1;
      break;
    }
  }
}
