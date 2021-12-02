#include <iostream>
#include <vector>

using namespace std;

int N;
long long B[100];

void check(vector<long long> numbers) {
  if (numbers.size() == N) {
    for (const auto &elem : numbers) {
      cout << elem << ' ';
    }
    return;
  }

  long long c1 = numbers.back() * 2;
  long long c2 = numbers.back() % 3 == 0 ? numbers.back() / 3 : 0;

  for (int i = 0; i < N; i++) {
    if (B[i] == c1) {
      numbers.push_back(c1);
      check(numbers);
    }

    if (B[i] == c2) {
      numbers.push_back(c2);
      check(numbers);
    }
  }
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }

  for (int i = 0; i < N; i++) {
    check({B[i]});
  }
}