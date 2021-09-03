#include <iostream>
#include <numeric>
#include <stack>

using namespace std;

int main() {
  string s;
  stack<char> left, right;
  int alphabet[26] = {
      0,
  };

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    alphabet[s[i] - 'A']++;
  }

  for (int i = 0; i < 26; i++) {
    int repeat = alphabet[i] / 2;
    for (int j = 0; j < repeat; j++) {
      left.push(i + 'A');
    }
    for (int j = 0; j < repeat; j++) {
      right.push(i + 'A');
    }
    alphabet[i] -= repeat * 2;
  }

  int sum = accumulate(begin(alphabet), end(alphabet), 0, plus<>());
  if (sum == 0 || sum == 1) {
    string result = "";
    while (!left.empty()) {
      result = left.top() + result;
      left.pop();
    }

    for (int i = 0; i < 26; i++) {
      if (alphabet[i] == 1) {
        result += (char)(i + 'A');
      }
    }

    while (!right.empty()) {
      result += right.top();
      right.pop();
    }

    cout << result;
  } else {
    cout << "I'm Sorry Hansoo";
  }
}