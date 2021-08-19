#include <iostream>

using namespace std;

string USELESS[10] = {"i", "pa",  "te",   "ni", "niti",
                      "a", "ali", "nego", "no", "ili"};

bool isUseless(string s) {
  for (int i = 0; i < 10; i++) {
    if (s == USELESS[i]) return true;
  }

  return false;
}

int main() {
  string s, result = "";

  cin >> s;

  result += toupper(s[0]);

  while (cin >> s) {
    if (!isUseless(s)) result += toupper(s[0]);
  }

  cout << result;
}