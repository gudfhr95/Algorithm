#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool sortFunction(pair<string, int> a, pair<string, int> b) {
  return a.second > b.second;
}

int main() {
  int T, N;
  string name;
  int num;

  cin >> T;

  while (T--) {
    vector<pair<string, int>> schools;
    cin >> N;
    for (int i = 0; i < N; ++i) {
      cin >> name >> num;
      schools.push_back({name, num});
    }

    sort(schools.begin(), schools.end(), sortFunction);

    cout << schools[0].first << '\n';
  }
}