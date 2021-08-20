#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a, b;
  vector<int> seq;

  for (int i = 1; i <= 20; i++) {
    seq.push_back(i);
  }

  for (int i = 0; i < 10; i++) {
    cin >> a >> b;

    reverse(seq.begin() + a - 1, seq.begin() + b);
  }

  for (const auto &elem : seq) {
    cout << elem << ' ';
  }
}