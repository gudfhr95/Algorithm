#include <iostream>

using namespace std;

int main() {
  int N, p, cont = 0, result = 0;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> p;
    if (p == 1) {
      result += p;
      result += cont;
      cont++;
    } else {
      cont = 0;
    }
  }

  cout << result;
}