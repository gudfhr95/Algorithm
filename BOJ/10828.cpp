#include <iostream>
#include <stack>
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
  stack<int> stack;

  cin >> N;
  cin.ignore();

  while (N--) {
    getline(cin, cmd);

    cmd_splited = split(cmd, " ");

    if (cmd_splited[0] == "push") {
      stack.push(stoi(cmd_splited[1]));
    } else if (cmd_splited[0] == "pop") {
      if (stack.empty())
        cout << -1 << '\n';
      else {
        cout << stack.top() << '\n';
        stack.pop();
      }
    } else if (cmd_splited[0] == "size") {
      cout << stack.size() << '\n';
    } else if (cmd_splited[0] == "empty") {
      cout << (int)stack.empty() << '\n';
    } else if (cmd_splited[0] == "top") {
      if (stack.empty())
        cout << -1 << '\n';
      else
        cout << stack.top() << '\n';
    }
  }
}