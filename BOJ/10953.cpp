#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string s, string delim) {
  vector<string> result;
  size_t previous = 0, current;
  string substring;

  current = s.find(delim);
  while (current != string::npos) {
    substring = s.substr(previous, current - previous);
    result.push_back(substring);
    previous = current + 1;
    current = s.find(delim, previous);
  }
  substring = s.substr(previous, current - previous);
  result.push_back(substring);

  return result;
}

int main() {
  int T, result;
  string s;
  vector<string> splited;

  cin >> T;

  while (T--) {
    cin >> s;

    result = 0;
    splited = split(s, ",");

    for (const auto &elem : splited) {
      result += stoi(elem);
    }

    cout << result << '\n';
  }
}