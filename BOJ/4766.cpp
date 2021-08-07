#include <iostream>
#include <vector>

using namespace std;

int main() {
  float degree;
  vector<float> degrees;

  while (true) {
    cin >> degree;

    if (degree == 999) break;

    degrees.push_back(degree);
  }

  for (int i = 0; i < degrees.size() - 1; i++) {
    printf("%.2f\n", degrees[i + 1] - degrees[i]);
  }
}