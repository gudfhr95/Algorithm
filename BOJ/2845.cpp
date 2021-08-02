#include <iostream>

using namespace std;

int main() {
  int L, P, participants;
  int total;

  cin >> L >> P;

  total = L * P;

  for (int i = 0; i < 5; i++) {
    cin >> participants;
    cout << participants - total << ' ';
  }
}