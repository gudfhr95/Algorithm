#include <iostream>

using namespace std;

int count(string s, string delim) {
  int result = 0;
  size_t prev = 0, cur;

  cur = s.find(delim);
  while (cur != string::npos) {
    result++;
    prev = cur + 1;
    cur = s.find(delim, prev);
  }

  return result;
}

int main() {
  string s;
  int joi = 0, ioi = 0;
  size_t prev = 0, cur;

  cin >> s;

  cout << count(s, "JOI") << '\n';
  cout << count(s, "IOI");
}