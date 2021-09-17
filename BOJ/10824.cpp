#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b, c, d;

  cin >> a >> b >> c >> d;

  cout << stoll(a + b) + stoll(c + d);
}