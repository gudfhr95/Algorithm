#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string NAME[6] = {"Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"};
string SAMENAME[6] = {"Habb Yakk", "Dobara", "Dousa",
                      "Dorgy",     "Dabash", "Dosh"};

int main() {
  int T, a, b;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    cin >> a >> b;

    vector<int> dice = {a, b};
    sort(dice.begin(), dice.end(), greater<>());

    printf("Case %d: ", i);

    if (dice[0] == dice[1]) {
      cout << SAMENAME[dice[0] - 1] << '\n';
      continue;
    } else if (dice[0] == 6 && dice[1] == 5) {
      printf("Sheesh Beesh\n");
      continue;
    }

    cout << NAME[dice[0] - 1] << ' ' << NAME[dice[1] - 1] << '\n';
  }
}