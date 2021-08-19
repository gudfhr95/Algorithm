#include <iostream>

using namespace std;

int main() {
  int T, N;
  int sum, num;
  float average;
  int* scores;

  cin >> T;

  for (int test_case = 0; test_case < T; ++test_case) {
    cin >> N;

    scores = new int[N];
    sum = 0;
    for (int i = 0; i < N; ++i) {
      cin >> scores[i];
      sum += scores[i];
    }

    average = sum / float(N);

    num = 0;
    for (int i = 0; i < N; i++) {
      if (scores[i] > average) {
        ++num;
      }
    }
    cout << fixed;
    cout.precision(3);
    cout << (num / float(N) * 100) << '%' << endl;
  }

  return 0;
}