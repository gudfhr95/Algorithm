#include <iostream>
using namespace std;
int main() {
  char w[3];
  float c = 0;
  cin >> w;
  for (int i = 0; i < 2; i++) {
    switch (w[i]) {
      case 'A':
        c = 4.3;
        break;
      case 'B':
        c = 3.3;
        break;
      case 'C':
        c = 2.3;
        break;
      case 'D':
        c = 1.3;
        break;
      case 'F':
        c = 0.0;
        break;
      case '0':
        c -= 0.3;
        break;
      case '-':
        c -= 0.6;
        break;
    }
  }
  printf("%.1f", c);
}