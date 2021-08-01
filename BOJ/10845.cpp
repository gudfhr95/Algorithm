#include <iostream>
#include <queue>
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
  queue<int> q;

  cin >> N;
  cin.ignore();

  while (N--) {
    getline(cin, cmd);

    cmd_splited = split(cmd, " ");

    if (cmd_splited[0] == "push") {
      q.push(stoi(cmd_splited[1]));
    } else if (cmd_splited[0] == "pop") {
      if (q.empty())
        cout << -1 << '\n';
      else {
        cout << q.front() << '\n';
        q.pop();
      }
    } else if (cmd_splited[0] == "size") {
      cout << q.size() << '\n';
    } else if (cmd_splited[0] == "empty") {
      cout << (int)q.empty() << '\n';
    } else if (cmd_splited[0] == "front") {
      if (q.empty())
        cout << -1 << '\n';
      else
        cout << q.front() << '\n';
    } else if (cmd_splited[0] == "back") {
      if (q.empty())
        cout << -1 << '\n';
      else
        cout << q.back() << '\n';
    }
  }
}