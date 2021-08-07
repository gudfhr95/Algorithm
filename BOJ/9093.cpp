#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string s, string delim) {
  vector<string> result;
  size_t prev = 0, cur;
  string substring;

  cur = s.find(delim);
  while (cur != string::npos) {
    substring = s.substr(prev, cur - prev);
    result.push_back(substring);
    prev = cur + 1;
    cur = s.find(delim, prev);
  }
  substring = s.substr(prev, cur - prev);
  result.push_back(substring);

  return result;
}

int main() {
  int T;
  string s, result;
  vector<string> splited;

  cin >> T;
  cin.ignore();

  while (T--) {
    getline(cin, s);

    result = "";
    splited = split(s, " ");

    for (int i = 0; i < splited.size(); i++) {
      reverse(splited[i].begin(), splited[i].end());
      result += splited[i];
      if (i != splited.size() - 1) result += ' ';
    }

    cout << result << '\n';
  }
}