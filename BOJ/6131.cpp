#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int N, result = 0;

  cin >> N;

  for (int a = 1; a <= 500; a++) {
    for (int b = 1; b <= 500; b++) {
      if (pow(a, 2) == (pow(b, 2) + N)) result++;
    }
  }

  cout << result;
}