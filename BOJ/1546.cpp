#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<double> scores;
  int m = -987654321;

  scanf("%d", &n);

  int temp;
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    scores.push_back(double(temp));
  }

  for (const auto &elem : scores) {
    if (elem > m) {
      m = elem;
    }
  }

  for (auto &elem : scores) {
    elem /= double(m);
    elem *= 100;
  }

  double sum = 0;
  for (const auto &elem : scores) {
    sum += elem;
  }
  printf("%lf", (sum / n));
}