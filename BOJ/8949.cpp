#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string a, b, result = "";
  int temp;

  cin >> a >> b;

  if (b.length() > a.length()) swap(a, b);

  result = a.substr(0, a.length() - b.length());

  for (int i = 0; i < b.length(); i++) {
    temp = (a[a.length() - b.length() + i] - '0') + (b[i] - '0');
    result += to_string(temp);
  }

  cout << result;
}