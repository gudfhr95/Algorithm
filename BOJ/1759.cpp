#include <algorithm>
#include <iostream>

using namespace std;

bool selected[17];
char password[17];
char alphabet[17];

void getPassword(int index, int consonant, int vowel, int c, int l) {
  if (index == l) {
    if (consonant < 2 || vowel < 1) return;

    for (int i = 0; i < l; i++) {
      cout << password[i];
    }
    cout << '\n';
    return;
  }

  for (int i = 0; i < c; i++) {
    if (selected[i]) continue;

    if (index > 0 && password[index - 1] > alphabet[i]) continue;

    selected[i] = true;

    password[index] = alphabet[i];
    if (alphabet[i] == 'a' || alphabet[i] == 'e' || alphabet[i] == 'i' ||
        alphabet[i] == 'o' || alphabet[i] == 'u') {
      getPassword(index + 1, consonant, vowel + 1, c, l);
    } else {
      getPassword(index + 1, consonant + 1, vowel, c, l);
    }

    selected[i] = false;
  }
}

int main() {
  int L, C;

  cin >> L >> C;

  for (int i = 0; i < C; i++) {
    cin >> alphabet[i];
  }

  sort(alphabet, alphabet + C);

  getPassword(0, 0, 0, C, L);
}