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
  cin.ignore();

  while (N--) {
    getline(cin, s);

    splited = split(s, " ");

    for (int i = 2; i < splited.size(); i++) {
      cout << splited[i] << ' ';
    }

    for (int i = 0; i < 2; i++) {
      cout << splited[i] << ' ';
    }

    cout << '\n';
  }
}
