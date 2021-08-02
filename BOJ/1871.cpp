#include <cmath>
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

int convertAlphabetToInt(string s) {
  int result = 0;
  for (int i = 0; i < 3; i++) {
    result += (s[i] - 'A') * pow(26, 2 - i);
  }
  return result;
}

int main() {
  int N;
  string number;
  vector<string> splited;

  cin >> N;

  while (N--) {
    cin >> number;
    splited = split(number, "-");

    if (abs(convertAlphabetToInt(splited[0]) - stoi(splited[1])) <= 100)
      cout << "nice\n";
    else
      cout << "not nice\n";
  }
}