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
  int N;
  string s;
  vector<string> splited;

  cin >> N;

  while (N--) {
    cin >> s;

    splited = split(s, "+");

    if (splited.size() == 1)
      cout << "skipped\n";
    else
      cout << stoi(splited[0]) + stoi(splited[1]) << '\n';
  }
}