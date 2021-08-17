#include <iostream>

using namespace std;

int GANDALF[6] = {1, 2, 3, 3, 4, 10};
int SAURON[7] = {1, 2, 2, 2, 3, 5, 10};

int main() {
  int T, n, gandalf, sauron;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    gandalf = sauron = 0;

    for (int j = 0; j < 6; j++) {
      cin >> n;
      gandalf += n * GANDALF[j];
    }

    for (int j = 0; j < 7; j++) {
      cin >> n;
      sauron += n * SAURON[j];
    }

    if (gandalf > sauron)
      printf("Battle %d: Good triumphs over Evil\n", i);
    else if (gandalf == sauron)
      printf("Battle %d: No victor on this battle field\n", i);
    else
      printf("Battle %d: Evil eradicates all trace of Good\n", i);
  }
}