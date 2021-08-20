#include <iostream>

using namespace std;

int main() {
  int n, count;
  string s;

  cin >> n;
  cin.ignore();

  while (n--) {
    getline(cin, s);

    count = 0;

    for (int i = 0; i < s.length(); i++) {
      if (tolower(s[i]) == 'g')
        count++;
      else if (tolower(s[i]) == 'b')
        count--;
    }

    cout << s << " is ";
    if (count > 0)
      cout << "GOOD\n";
    else if (count < 0)
      cout << "A BADDY\n";
    else
      cout << "NEUTRAL\n";
  }
}