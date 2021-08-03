#include <iostream>

using namespace std;

int SEATS[101] = {
    0,
};

int main() {
  int N, s, result = 0;

  cin >> N;

  while (N--) {
    cin >> s;

    if (SEATS[s] == 0)
      SEATS[s] = 1;
    else
      result++;
  }

  cout << result;
}