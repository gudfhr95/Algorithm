#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int P;
  string s, substring;
  int result[8];

  cin >> P;

  while (P--) {
    cin >> s;

    memset(result, 0, sizeof(result));

    for (int i = 0; i < 38; i++) {
      substring = s.substr(i, 3);
      if (substring == "TTT")
        result[0]++;
      else if (substring == "TTH")
        result[1]++;
      else if (substring == "THT")
        result[2]++;
      else if (substring == "THH")
        result[3]++;
      else if (substring == "HTT")
        result[4]++;
      else if (substring == "HTH")
        result[5]++;
      else if (substring == "HHT")
        result[6]++;
      else if (substring == "HHH")
        result[7]++;
    }

    for (int i = 0; i < 8; i++) {
      cout << result[i] << ' ';
    }
    cout << '\n';
  }
}