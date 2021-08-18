#include <iostream>

using namespace std;

int main() {
  int n, result;
  char op;

  cin >> result;

  while (true) {
    cin >> op;

    if (op == '=') {
      cout << result;
      break;
    }

    cin >> n;

    switch (op) {
      case '+':
        result += n;
        break;
      case '-':
        result -= n;
        break;
      case '*':
        result *= n;
        break;
      case '/':
        result /= n;
        break;
    }
  }
}