#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string S;

  cin >> S;

  int result = S.size();

  for (int i = 0; i < S.size(); i++) {
    char temp = S.at(i);
    if (i >= 2) {
      if (temp == '=') {
        if (S.at(i - 1) == 'z' && S.at(i - 2) == 'd') {
          result -= 2;
        } else {
          result -= 1;
        }
      }
      if (temp == '-') {
        result -= 1;
      }
      if (temp == 'j') {
        if (S.at(i - 1) == 'l') {
          result -= 1;
        }
        if (S.at(i - 1) == 'n') {
          result -= 1;
        }
      }
    } else if (i == 1) {
      if (temp == '=') {
        result -= 1;
      }
      if (temp == '-') {
        result -= 1;
      }
      if (temp == 'j') {
        if (S.at(i - 1) == 'l') {
          result -= 1;
        }
        if (S.at(i - 1) == 'n') {
          result -= 1;
        }
      }
    }
  }

  cout << result;

  return 0;
}