#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string s, string delim) {
  vector<string> result;
  size_t prev = 0, current;
  string substring;

  current = s.find(delim);
  while (current != string::npos) {
    substring = s.substr(prev, current - prev);
    result.push_back(substring);
    prev = current + 1;
    current = s.find(delim, prev);
  }
  substring = s.substr(prev, current - prev);
  result.push_back(substring);

  return result;
}

int main() {
  string s;
  vector<string> splited;

  cin >> s;

  splited = split(s, ",");

  cout << splited.size();

  return 0;
}