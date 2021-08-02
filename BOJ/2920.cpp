#include <iostream>

using namespace std;

string ascending = "12345678";
string descending = "87654321";

int main() {
  string s, seq = "";

  for (int i = 0; i < 8; i++) {
    cin >> s;
    seq += s;
  }

  if (seq == ascending)
    cout << "ascending";
  else if (seq == descending)
    cout << "descending";
  else
    cout << "mixed";
}