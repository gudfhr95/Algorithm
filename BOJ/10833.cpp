#include <iostream>

using namespace std;

int main() {
  int N, students, apples, rem = 0;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> students >> apples;
    rem += apples % students;
  }

  cout << rem;
}