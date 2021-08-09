#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  string s;
  vector<string> fish;

  cin >> N >> M;

  while (N--) {
    cin >> s;
    fish.push_back(s);
  }

  for (int i = 0; i < fish.size(); i++) {
    reverse(fish[i].begin(), fish[i].end());
  }

  for (const auto &elem : fish) {
    cout << elem << '\n';
  }
}
