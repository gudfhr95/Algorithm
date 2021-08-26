#include <iostream>

using namespace std;

int main() {
  int a_attack, a_hp, b_attack, b_hp;

  cin >> a_attack >> a_hp >> b_attack >> b_hp;

  while (true) {
    a_hp -= b_attack;
    b_hp -= a_attack;

    if (a_hp <= 0 && b_hp <= 0) {
      cout << "DRAW";
      break;
    } else if (a_hp <= 0) {
      cout << "PLAYER B";
      break;
    } else if (b_hp <= 0) {
      cout << "PLAYER A";
      break;
    }
  }
}