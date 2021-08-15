#include <iostream>

using namespace std;

int main() {
  int N, result = 0;
  string target, ring;

  cin >> target >> N;

  while (N--) {
    cin >> ring;
    ring += ring;

    if (ring.find(target) != string::npos) result++;
  }

  cout << result;
}