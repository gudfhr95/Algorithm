#include <iostream>

using namespace std;

char checkResult(int n) {
  char result = ' ';
  switch (n) {
    case 3:
      result = 'A';
      break;
    case 2:
      result = 'B';
      break;
    case 1:
      result = 'C';
      break;
    case 0:
      result = 'D';
      break;
    case 4:
      result = 'E';
      break;
  }

  return result;
}

int main() {
  int n, result;
  for (int i = 0; i < 3; i++) {
    result = 0;
    for (int j = 0; j < 4; j++) {
      cin >> n;
      result += n;
    }
    cout << checkResult(result) << '\n';
  }
}