#include <iostream>

using namespace std;

int main() {
  string s;
  int count = 0;

  while (getline(cin, s)) {
    count++;
  }

  cout << count;
}