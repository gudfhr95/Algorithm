#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int K, P, M, p, result;
  unordered_map<int, int> seats;

  cin >> K;

  while (K--) {
    cin >> P >> M;

    seats.clear();
    result = 0;

    for (int i = 0; i < P; i++) {
      cin >> p;

      if (seats.find(p) == seats.end())
        seats[p]++;
      else
        result++;
    }

    cout << result << '\n';
  }
}