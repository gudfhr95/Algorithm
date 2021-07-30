#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int M;
  int N;

  int sum = 0;
  int min = 0;

  cin >> M >> N;

  for (int i = M; i <= N; ++i) {
    float root = sqrt(i);
    if (root - (int)root == 0) {
      sum += i;
      if (min == 0) {
        min = i;
      }
    }
  }

  if (sum != 0)
    cout << sum << endl << min << endl;
  else
    cout << -1;
}