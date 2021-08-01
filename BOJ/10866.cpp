#include <deque>
#include <iostream>
#include <string>
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
  string cmd;
  vector<string> cmd_splited;
  deque<int> d;

  cin >> N;
  cin.ignore();

  while (N--) {
    getline(cin, cmd);

    cmd_splited = split(cmd, " ");

    if (cmd_splited[0] == "push_front") {
      d.push_front(stoi(cmd_splited[1]));
    } else if (cmd_splited[0] == "push_back") {
      d.push_back(stoi(cmd_splited[1]));
    } else if (cmd_splited[0] == "pop_front") {
      if (d.empty())
        cout << -1 << '\n';
      else {
        cout << d.front() << '\n';
        d.pop_front();
      }
    } else if (cmd_splited[0] == "pop_back") {
      if (d.empty())
        cout << -1 << '\n';
      else {
        cout << d.back() << '\n';
        d.pop_back();
      }
    } else if (cmd_splited[0] == "size") {
      cout << d.size() << '\n';
    } else if (cmd_splited[0] == "empty") {
      cout << (int)d.empty() << '\n';
    } else if (cmd_splited[0] == "front") {
      if (d.empty())
        cout << -1 << '\n';
      else
        cout << d.front() << '\n';
    } else if (cmd_splited[0] == "back") {
      if (d.empty())
        cout << -1 << '\n';
      else
        cout << d.back() << '\n';
    }
  }
}