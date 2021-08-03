#include <iostream>

using namespace std;

int main() {
  string a, b, op;
  int i = 1;
  bool result;

  while (true) {
    cin >> a >> op >> b;

    if (op == ">") {
      result = stoi(a) > stoi(b);
    } else if (op == ">=") {
      result = stoi(a) >= stoi(b);
    } else if (op == "<") {
      result = stoi(a) < stoi(b);
    } else if (op == "<=") {
      result = stoi(a) <= stoi(b);
    } else if (op == "==") {
      result = stoi(a) == stoi(b);
    } else if (op == "!=") {
      result = stoi(a) != stoi(b);
    } else {
      break;
    }

    if (result)
      printf("Case %d: true\n", i);
    else
      printf("Case %d: false\n", i);

    i++;
  }
}