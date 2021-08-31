#include <iostream>
#include <string>

using namespace std;

int main() {
  int seconds[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6,  6,  6,  7,
                     7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
  string S;
  int index;
  int result = 0;

  cin >> S;

  for (int i = 0; i < S.length(); ++i) {
    index = S.at(i) - 'A';
    result += seconds[index];
  }

  cout << result << '\n';

  return 0;
}