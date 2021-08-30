#include <iostream>

using namespace std;

int main() {
  int T;

  cin >> T;

  while (T--) {
    int stat[8] = {
        0,
    };

    for (int i = 0; i < 8; i++) {
      cin >> stat[i];
    }

    int hp = (stat[0] + stat[4]) < 1 ? 1 : (stat[0] + stat[4]);
    int mp = (stat[1] + stat[5]) < 1 ? 1 : (stat[1] + stat[5]);
    int attack = (stat[2] + stat[6]) < 0 ? 0 : (stat[2] + stat[6]);
    int defense = stat[3] + stat[7];

    cout << (hp) + (5 * mp) + (2 * attack) + (2 * defense) << '\n';
  }
}
