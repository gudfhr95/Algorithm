#include <iostream>

using namespace std;

int seq[1001];

void generateSequence(int end) {
  int n = 1;
  for (int i = 1; i <= end;) {
    for (int j = 1; j <= n; j++) {
      seq[i] = n;
      i++;
    }
    n++;
  }
}

int main() {
  int A, B, sum = 0;

  cin >> A >> B;

  generateSequence(1000);

  for (int i = A; i <= B; i++) {
    sum += seq[i];
  }

  cout << sum;
}