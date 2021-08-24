#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  long long x;
  vector<long long> points;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x;
    points.push_back(x);
  }

  long long result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      result += abs(points[i] - points[j]);
    }
  }

  cout << result;
}
