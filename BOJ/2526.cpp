#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, P;

  cin >> N >> P;

  vector<int> cycle;

  int remainder = N;
  while (true) {
    remainder = remainder * N % P;

    auto it = find(cycle.begin(), cycle.end(), remainder);
    if (it == cycle.end()) {
      cycle.push_back(remainder);
    } else {
      cout << cycle.end() - it;
      break;
    }
  }
}