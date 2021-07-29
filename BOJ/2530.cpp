#include <iostream>

using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int totalTime = ((A * 3600) + (B * 60) + C + D);
  printf("%d %d %d", (totalTime / 3600) % 24, ((totalTime % 3600) / 60) % 60,
         totalTime % 60);
}