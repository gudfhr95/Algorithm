#include <iostream>
#include <vector>

using namespace std;

int main() {
  int K, n, sum = 0;
  vector<int> numbers;

  cin >> K;

  while (K--) {
    cin >> n;

    if (n == 0)
      numbers.pop_back();
    else
      numbers.push_back(n);
  }

  for (const auto &elem : numbers) {
    sum += elem;
  }

  cout << sum;
}