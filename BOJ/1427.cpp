#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string s;

  cin >> s;

  sort(s.begin(), s.end(), greater<>());

  cout << s;
}