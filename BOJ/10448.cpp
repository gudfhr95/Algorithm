#include <iostream>
#include <vector>

using namespace std;

vector<int> TRIANGLE;

bool isTriangleNumber(int K) {
  for (int i = TRIANGLE.size() - 1; i >= 0; i--) {
    for (int j = TRIANGLE.size() - 1; j >= 0; j--) {
      for (int k = TRIANGLE.size() - 1; k >= 0; k--) {
        if (TRIANGLE[i] + TRIANGLE[j] + TRIANGLE[k] == K) return true;
      }
    }
  }

  return false;
}

int main() {
  int T, K;

  int i = 1, sum = 0;
  while (true) {
    sum += i;

    if (sum > 1000) break;

    TRIANGLE.push_back(sum);

    i++;
  }

  cin >> T;

  while (T--) {
    cin >> K;

    cout << isTriangleNumber(K) << '\n';
  }
}
