#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, p, l, s;
  vector<int> courses;

  cin >> n >> m;

  while (n--) {
    cin >> p >> l;

    vector<int> mileages;

    for (int i = 0; i < p; i++) {
      cin >> s;
      mileages.push_back(s);
    }

    if (p < l) {
      courses.push_back(1);
      continue;
    }

    sort(mileages.begin(), mileages.end(), greater<>());
    courses.push_back(mileages[l - 1]);
  }

  sort(courses.begin(), courses.end());

  int i;
  for (i = 0; i < courses.size(); i++) {
    m -= courses[i];

    if (m < 0) {
      break;
    }
  }
  cout << i;
}