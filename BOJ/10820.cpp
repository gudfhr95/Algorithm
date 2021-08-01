#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int upper, lower, number, space;
  string s;

  while (getline(cin, s)) {
    upper = 0, lower = 0, number = 0, space = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ')
        space++;
      else if (isdigit(s[i]))
        number++;
      else if (isupper(s[i]))
        upper++;
      else if (islower(s[i]))
        lower++;
    }

    printf("%d %d %d %d\n", lower, upper, number, space);
  }
}