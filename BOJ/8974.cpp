#include <iostream>
#include <vector>

using namespace std;

int main() {
  int A, B, result = 0;
  vector<int> seq;

  cin >> A >> B;

  for (int i = 1; i <= 50; i++) {
    for (int j = 1; j <= i; j++) {
      seq.push_back(i);
    }
  }

  for (int i = A - 1; i <= B - 1; i++) {
    result += seq[i];
  }

  cout << result;
}