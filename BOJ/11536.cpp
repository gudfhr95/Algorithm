#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isIncreasing(vector<string> players) {
  vector<string> increasing = players;
  sort(increasing.begin(), increasing.end());

  for (int i = 0; i < players.size(); i++) {
    if (players[i] != increasing[i]) return false;
  }

  return true;
}

bool isDecreasing(vector<string> players) {
  vector<string> decreasing = players;
  sort(decreasing.begin(), decreasing.end(), greater<>());

  for (int i = 0; i < players.size(); i++) {
    if (players[i] != decreasing[i]) return false;
  }

  return true;
}

int main() {
  int N;
  string s;
  vector<string> players;

  cin >> N;

  while (N--) {
    cin >> s;
    players.push_back(s);
  }

  if (isIncreasing(players))
    cout << "INCREASING";
  else if (isDecreasing(players))
    cout << "DECREASING";
  else
    cout << "NEITHER";
}