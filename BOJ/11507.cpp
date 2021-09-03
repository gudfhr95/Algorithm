#include <iostream>
#include <numeric>

using namespace std;

int main() {
  string s;
  int P[13] = {
      0,
  };
  int K[13] = {
      0,
  };
  int H[13] = {
      0,
  };
  int T[13] = {
      0,
  };

  cin >> s;

  for (int i = 0; i < s.length(); i += 3) {
    string card = s.substr(i, 3);
    int number = stoi(card.substr(1, 2)) - 1;

    switch (card[0]) {
      case 'P':
        P[number]++;
        if (P[number] == 2) {
          cout << "GRESKA";
          return 0;
        }
        break;
      case 'K':
        K[number]++;
        if (K[number] == 2) {
          cout << "GRESKA";
          return 0;
        }
        break;
      case 'H':
        H[number]++;
        if (H[number] == 2) {
          cout << "GRESKA";
          return 0;
        }
        break;
      case 'T':
        T[number]++;
        if (T[number] == 2) {
          cout << "GRESKA";
          return 0;
        }
        break;
    }
  }

  cout << 13 - accumulate(begin(P), end(P), 0, plus<int>()) << ' ';
  cout << 13 - accumulate(begin(K), end(K), 0, plus<int>()) << ' ';
  cout << 13 - accumulate(begin(H), end(H), 0, plus<int>()) << ' ';
  cout << 13 - accumulate(begin(T), end(T), 0, plus<int>()) << ' ';
}