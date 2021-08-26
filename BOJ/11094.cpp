#include <iostream>

using namespace std;

int main() {
  int N;
  string s;

  cin >> N;
  cin.ignore();

  while (N--) {
    getline(cin, s);

    size_t pos = s.find("Simon says");
    if (pos != string::npos) {
      cout << s.substr(10, s.length() - 10) << '\n';
    }
  }
}