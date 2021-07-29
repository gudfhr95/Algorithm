#include <iostream>

using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int totalTime = (A * 60 + B + C) % 1440;
  printf("%d %d", (totalTime / 60) % 24, totalTime % 60);
}