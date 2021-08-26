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

bool isTautogram(string s) {
  vector<string> splited = split(s, " ");

  char tautogram = tolower(splited[0][0]);

  for (int i = 1; i < splited.size(); i++) {
    if (tolower(splited[i][0]) != tautogram) return false;
  }

  return true;
}

int main() {
  string s;

  while (true) {
    getline(cin, s);

    if (s == "*") break;

    if (isTautogram(s))
      cout << "Y\n";
    else
      cout << "N\n";
  }
}