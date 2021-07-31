#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  vector<int> dwarfs;

  for (int i = 0; i < 9; i++) {
    cin >> t;
    dwarfs.push_back(t);
  }

  int r = 7;
  vector<bool> temp(dwarfs.size(), true);
  for (int i = 0; i < dwarfs.size() - r; i++) temp[i] = false;

  do {
    int sum = 0;
    vector<int> result;
    for (int i = 0; i < dwarfs.size(); i++) {
      if (temp[i]) {
        sum += dwarfs[i];
        result.push_back(dwarfs[i]);
      }
    }
    if (sum == 100) {
      sort(result.begin(), result.end());
      for (const auto &elem : result) {
        cout << elem << '\n';
      }
      break;
    }
  } while (next_permutation(temp.begin(), temp.end()));
}