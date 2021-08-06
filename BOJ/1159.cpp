#include <iostream>
#include <map>

using namespace std;

int main() {
  int N;
  string s;
  map<char, int> player;
  bool flag = false;

  cin >> N;

  while (N--) {
    cin >> s;

    player[s[0]]++;
  }

  for (const auto &elem : player) {
    if (elem.second >= 5) {
      flag = true;
      break;
    }
  }

  if (flag) {
    for (const auto &elem : player) {
      if (elem.second >= 5) cout << elem.first;
    }
  } else
    cout << "PREDAJA";
}