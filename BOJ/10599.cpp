#include <iostream>

using namespace std;

int main() {
  int birth_min, birth_max, death_min, death_max;

  while (true) {
    cin >> birth_min >> birth_max >> death_min >> death_max;

    if (birth_min == 0 && birth_max == 0 && death_min == 0 && death_max == 0)
      break;

    cout << death_min - birth_max << ' ' << death_max - birth_min << '\n';
  }
}
