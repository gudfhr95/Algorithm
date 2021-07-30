#include <iostream>
#include <vector>

using namespace std;

void perfect(int n) {
  vector<int> result;
  int sum = 0;

  for (int i = 1; i < n; ++i) {
    if (n % i == 0) {
      result.push_back(i);
    }
  }

  for (const auto &elem : result) {
    sum += elem;
  }

  if (n == sum) {
    cout << n << " = ";
    for (int i = 0; i < result.size() - 1; ++i) {
      cout << result[i] << " + ";
    }
    cout << result[result.size() - 1] << "\n";
  } else {
    cout << n << " is NOT perfect.\n";
  }
}

int main() {
  int n;
  while (true) {
    cin >> n;
    if (n == -1) {
      break;
    }
    perfect(n);
  }
}