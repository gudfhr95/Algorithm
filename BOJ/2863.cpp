#include <iostream>

using namespace std;

int main() {
  int A, B, C, D;
  float fraction[4];

  cin >> A >> B >> C >> D;

  fraction[0] = ((A * D) + (B * C)) / (float)(C * D);
  fraction[1] = ((C * B) + (A * D)) / (float)(B * D);
  fraction[2] = ((D * A) + (C * B)) / (float)(A * B);
  fraction[3] = ((B * C) + (A * D)) / (float)(A * C);

  float max = -987654321;

  for (int i = 0; i < 4; i++) {
    if (fraction[i] > max) {
      max = fraction[i];
    }
  }

  for (int i = 0; i < 4; i++) {
    if (fraction[i] == max) {
      cout << i;
    }
  }
}