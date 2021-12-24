#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
  int N;

  cin >> N;

  vector<pair<long long, long long>> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i].first >> p[i].second;
  }

  long long result = 0;
  long long x1, y1, x2, y2, x3, y3;
  tie(x1, y1) = p[0];
  for (int i = 1; i < N - 1; i++) {
    tie(x2, y2) = p[i];
    tie(x3, y3) = p[i + 1];

    result += x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;
  }
  result = abs(result);
  
  cout << result / 2 << '.';
  if (result % 2 == 0) {
    cout << '0';
  } else {
    cout << '5';
  }
}