#include <iostream>

using namespace std;

int main() {
  string H, N;

  cin >> H >> N;

  int result = 0;
  size_t prev = 0, cur;
  string substring;

  while (true) {
    cur = H.find(N, prev);
    if (cur != string::npos) {
      result++;
      prev = cur + 1;
    } else {
      break;
    }
  }

  cout << result;
}