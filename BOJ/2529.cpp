#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isNumber(string s, vector<char> ops) {
  for (int i = 0; i < s.length() - 1; i++) {
    if (ops[i] == '<') {
      if (s[i] >= s[i + 1]) {
        return false;
      }
    } else {
      if (s[i] <= s[i + 1]) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  int k;
  char c;
  vector<char> ops;

  cin >> k;

  for (int i = 0; i < k; i++) {
    cin >> c;
    ops.push_back(c);
  }

  string s = "";
  for (int i = 0; i < 10; i++) {
    s += (char)(i + '0');
  }

  vector<string> result;
  do {
    string num = s.substr(0, k + 1);
    if (isNumber(num, ops)) {
      result.push_back(num);
    }
    reverse(s.begin() + k + 1, s.end());
  } while (next_permutation(s.begin(), s.end()));

  printf("%s\n%s", result[result.size() - 1].c_str(), result[0].c_str());
}