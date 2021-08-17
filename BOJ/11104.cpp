#include <bitset>
#include <iostream>

using namespace std;

int main() {
  int n;
  string s;

  cin >> n;

  while (n--) {
    cin >> s;
    bitset<24> bit(s);
    cout << bit.to_ulong() << '\n';
  }
}