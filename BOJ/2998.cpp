#include <iostream>

using namespace std;

int main() {
  string s;
  string result = "";

  cin >> s;

  switch (s.length() % 3) {
    case 1:
      s = "00" + s;
      break;
    case 2:
      s = "0" + s;
      break;
  }

  for (int i = 0; i < s.length(); i += 3) {
    string digit = s.substr(i, 3);
    if (digit == "000")
      result += "0";
    else if (digit == "001")
      result += "1";
    else if (digit == "010")
      result += "2";
    else if (digit == "011")
      result += "3";
    else if (digit == "100")
      result += "4";
    else if (digit == "101")
      result += "5";
    else if (digit == "110")
      result += "6";
    else if (digit == "111")
      result += "7";
  }

  cout << result;
}