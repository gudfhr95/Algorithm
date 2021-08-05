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
  int T, result;
  string s;
  vector<string> inputs;

  cin >> T;
  cin.ignore();

  while (T--) {
    getline(cin, s);

    result = 0;

    inputs = split(s, " ");

    for (const auto &elem : inputs) {
      result += stoi(elem);
    }

    cout << result << '\n';
  }
}