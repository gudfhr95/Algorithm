#include <cmath>
#include <iostream>

using namespace std;

int main() {
  string s;
  string result = "";

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    switch (s[i]) {
      case '0':
        result += "000";
        break;
      case '1':
        result += "001";
        break;
      case '2':
        result += "010";
        break;
      case '3':
        result += "011";
        break;
      case '4':
        result += "100";
        break;
      case '5':
        result += "101";
        break;
      case '6':
        result += "110";
        break;
      case '7':
        result += "111";
        break;
    }
  }

  if (result == "000") {
    cout << '0';
  } else {
    for (int i = 0; i < result.length(); i++) {
      if (result[i] == '1') {
        result = result.substr(i, result.length() - i);
        break;
      }
    }
    cout << result;
  }
}