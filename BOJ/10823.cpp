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
  string s, total_string = "";
  vector<string> splited;
  int result = 0;

  while (cin >> s) {
    total_string += s;
  }

  splited = split(total_string, ",");

  for (const auto &elem : splited) {
    result += stoi(elem);
  }

  cout << result;
}