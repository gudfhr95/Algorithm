#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int T, index;
  string s, answer;

  cin >> T;

  while (T--) {
    cin >> index >> s;
    answer = "";

    answer += s.substr(0, index - 1) + s.substr(index, s.length());
    cout << answer << '\n';
  }
}