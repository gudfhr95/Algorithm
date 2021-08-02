#include <iostream>

using namespace std;

int main() {
  int s, minguk = 0, mansae = 0;

  for (int i = 0; i < 4; i++) {
    cin >> s;
    minguk += s;
  }

  for (int i = 0; i < 4; i++) {
    cin >> s;
    mansae += s;
  }

  if (minguk > mansae)
    cout << minguk;
  else
    cout << mansae;
}