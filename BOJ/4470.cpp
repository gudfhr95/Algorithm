#include <iostream>

using namespace std;

int main() {
  int N;
  string s;

  cin >> N;
  cin.ignore();

  for (int i = 1; i <= N; i++) {
    getline(cin, s);
    cout << i << ". " << s << '\n';
  }
}