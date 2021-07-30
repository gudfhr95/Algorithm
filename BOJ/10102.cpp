#include <iostream>

using namespace std;

int votes[2] = {
    0,
};

int main() {
  float V;
  string s;

  cin >> V >> s;

  for (int i = 0; i < s.length(); ++i) {
    votes[s[i] - 'A']++;
  }

  if (votes[0] > (V / 2)) {
    cout << 'A';
  } else if (votes[0] == (V / 2)) {
    cout << "Tie";
  } else {
    cout << 'B';
  }

  return 0;
}