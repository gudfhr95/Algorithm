#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, n;

  while (true) {
    cin >> N;

    if (N == 0) break;

    vector<int> inputs;
    int last = 0;

    for (int i = 0; i < N; i++) {
      cin >> n;

      if (n != last) inputs.push_back(n);

      last = n;
    }

    for (const auto &elem : inputs) {
      cout << elem << ' ';
    }
    cout << "$\n";
  }
}