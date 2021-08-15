#include <iostream>

using namespace std;

float poundToKillogram(float lb) { return lb * 0.4536; }
float killogramToPound(float kg) { return kg * 2.2046; }
float literToGallon(float l) { return l * 0.2642; }
float gallonToLiter(float g) { return g * 3.7854; }

int main() {
  int T;
  float n;
  string m;

  cin >> T;

  while (T--) {
    cin >> n >> m;

    if (m == "kg")
      printf("%.4f lb", killogramToPound(n));
    else if (m == "lb")
      printf("%.4f kg", poundToKillogram(n));
    else if (m == "l")
      printf("%.4f g", literToGallon(n));
    else if (m == "g")
      printf("%.4f l", gallonToLiter(n));

    cout << '\n';
  }
}
