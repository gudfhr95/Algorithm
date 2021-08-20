#include <iostream>

using namespace std;

int main() {
  int K, h;
  string s;

  cin >> K;

  for (int i = 1; i <= K; i++) {
    cin >> h >> s;

    for (int j = 0; j < s.length(); j++) {
      if (s[j] == 'c')
        h++;
      else
        h--;
    }

    printf("Data Set %d:\n%d\n\n", i, h);
  }
}