#include <iostream>
#include <vector>

using namespace std;

vector<int> toBinary(int n) {
  vector<int> result;

  while (n > 0) {
    result.push_back(n % 2);
    n /= 2;
  }

  return result;
}

int main() {
  int T, n;
  vector<int> binary;

  cin >> T;

  while (T--) {
    cin >> n;
    binary = toBinary(n);
    for (int i = 0; i < binary.size(); i++) {
      if (binary[i] == 1) cout << i << ' ';
    }
    cout << '\n';
  }
}