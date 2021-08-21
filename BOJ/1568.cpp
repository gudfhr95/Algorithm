#include <iostream>

using namespace std;

int main() {
  long long N;
  int i = 1, result = 0;

  cin >> N;

  while (N > 0) {
    if (i > N) {
      i = 1;
      continue;
    }

    N -= i;
    i++;
    result++;
  }

  cout << result;
}
