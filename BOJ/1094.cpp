#include <bitset>
#include <iostream>

using namespace std;

int main() {
  int X;

  cin >> X;

  bitset<8> bit(X);
  string s = bit.to_string();

  int result = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '1') result++;
  }

  cout << result;
}