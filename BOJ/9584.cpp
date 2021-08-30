#include <iostream>
#include <vector>

using namespace std;

bool isMatched(string scanner, string registration) {
  for (int i = 0; i < scanner.length(); i++) {
    if (scanner[i] == '*') continue;

    if (scanner[i] != registration[i]) return false;
  }

  return true;
}

int main() {
  int n;
  string scanner, registration;
  vector<string> result;

  cin >> scanner >> n;

  while (n--) {
    cin >> registration;

    if (isMatched(scanner, registration)) result.push_back(registration);
  }

  cout << result.size() << '\n';

  for (const auto &elem : result) {
    cout << elem << '\n';
  }
}
