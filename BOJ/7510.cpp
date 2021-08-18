#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, t;
  vector<int> v;

  cin >> n;

  for (int i = 1; i <= n; i++) {
    v.clear();

    for (int i = 0; i < 3; i++) {
      cin >> t;
      v.push_back(t);
    }

    sort(v.begin(), v.end());

    if (pow(v[0], 2) + pow(v[1], 2) == pow(v[2], 2))
      printf("Scenario #%d:\nyes\n\n", i);
    else
      printf("Scenario #%d:\nno\n\n", i);
  }
}