#include <iostream>
#include <vector>

using namespace std;

string resize(string s) {
  string result = "";

  for (int i = 0; i < s.length(); i++) {
    result += s[i];
    result += s[i];
  }

  return result;
}

void isEyfa(vector<string> s1, vector<string> s2) {
  for (int i = 0; i < s1.size(); i++) {
    if (resize(s1[i]) != s2[i]) {
      cout << "Not Eyfa";
      return;
    }
  }

  cout << "Eyfa";
  return;
}

int main() {
  int N, M;
  string s;
  vector<string> s1, s2;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> s;
    s1.push_back(s);
  }

  for (int i = 0; i < N; i++) {
    cin >> s;
    s2.push_back(s);
  }

  isEyfa(s1, s2);
}