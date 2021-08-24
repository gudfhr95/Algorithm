#include <algorithm>
#include <iostream>

using namespace std;

void nth_permutation(string s, int n) {
  int count = 1;
  string original = s;

  do {
    if (count == n) break;
    count++;
  } while (next_permutation(s.begin(), s.end()));

  if (s == original)
    cout << "No permutation\n";
  else
    cout << s << '\n';
}

int main() {
  string s;
  int n;

  while (cin >> s >> n) {
    cout << s << " " << n << " = ";
    nth_permutation(s, n);
  }
}
