#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int p;
  vector<int> hamburgers, beverages;

  for (int i = 0; i < 3; i++) {
    cin >> p;
    hamburgers.push_back(p);
  }

  for (int i = 0; i < 2; i++) {
    cin >> p;
    beverages.push_back(p);
  }

  sort(hamburgers.begin(), hamburgers.end());
  sort(beverages.begin(), beverages.end());

  cout << hamburgers[0] + beverages[0] - 50;
}