#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s;
  vector<int> answer;

  for (int i = 1; i <= 5; i++) {
    cin >> s;
    if (s.find("FBI") != string::npos) answer.push_back(i);
  }

  if (answer.size() == 0) {
    cout << "HE GOT AWAY!";
  } else {
    for (const auto &elem : answer) {
      cout << elem << ' ';
    }
  }
}