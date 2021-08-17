#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;

  int max = N / 5;
  int remain;

  for (int i = max; i >= 0; --i) {
    remain = N - (i * 5);
    if ((remain % 3) == 0) {
      cout << (i + (remain / 3));
      return 0;
    }
  }

  cout << -1;

  return 0;
}