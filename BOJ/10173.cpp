#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;

  while (true) {
    getline(cin, s);

    if (s == "EOI") break;

    // 소문자 변환
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    if (s.find("nemo") != string::npos)
      cout << "Found\n";
    else
      cout << "Missing\n";
  }
}