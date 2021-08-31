#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int k, s;

  while (true) {
    cin >> k;

    if (k == 0) break;

    vector<int> S;
    for (int i = 0; i < k; i++) {
      cin >> s;
      S.push_back(s);
    }

    vector<bool> temp(k, false);
    for (int i = 0; i < 6; i++) {
      temp[i] = true;
    }

    do {
      for (int i = 0; i < k; i++) {
        if (temp[i]) cout << S[i] << ' ';
      }
      cout << '\n';
    } while (prev_permutation(temp.begin(), temp.end()));

    cout << '\n';
  }
}