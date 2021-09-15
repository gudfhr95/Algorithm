#include <deque>
#include <iostream>

using namespace std;

int main() {
  string s;
  deque<char> d;

  getline(cin, s);

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '<') {
      while (!d.empty()) {
        cout << d.back();
        d.pop_back();
      }

      while (s[i] != '>') {
        d.push_back(s[i]);
        i++;
      }
      while (!d.empty()) {
        cout << d.front();
        d.pop_front();
      }
      cout << s[i];
    } else {
      if (s[i] == ' ') {
        while (!d.empty()) {
          cout << d.back();
          d.pop_back();
        }
        cout << s[i];
      } else {
        d.push_back(s[i]);
      }
    }
  }

  while (!d.empty()) {
    cout << d.back();
    d.pop_back();
  }
}