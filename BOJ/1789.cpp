#include <iostream>

using namespace std;

int main() {
  long long N;
  int i = 1;
  cin >> N;

  while (true) {
    N -= i;
    if (N < 0) {
      break;
    }
    i++;
  }
  cout << i - 1;
}