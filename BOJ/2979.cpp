#include <iostream>

using namespace std;

int TRUCKS[101] = {
    0,
};

int main() {
  int A, B, C, in, out, result = 0;

  cin >> A >> B >> C;

  for (int i = 0; i < 3; i++) {
    cin >> in >> out;

    for (int j = in; j < out; j++) {
      TRUCKS[j]++;
    }
  }

  for (int i = 1; i <= 100; i++) {
    switch (TRUCKS[i]) {
      case 1:
        result += TRUCKS[i] * A;
        break;
      case 2:
        result += TRUCKS[i] * B;
        break;
      case 3:
        result += TRUCKS[i] * C;
        break;
    }
  }

  cout << result;
}