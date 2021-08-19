#include <iostream>

using namespace std;

int main() {
  int T, d, n, s, p;

  cin >> T;

  while (T--) {
    cin >> d >> n >> s >> p;

    int parallel = d + (n * p);
    int serial = n * s;

    if (serial < parallel)
      cout << "do not parallelize\n";
    else if (serial > parallel)
      cout << "parallelize\n";
    else
      cout << "does not matter";
  }
}