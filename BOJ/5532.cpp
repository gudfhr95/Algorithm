#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int L, A, B, C, D;

  cin >> L >> A >> B >> C >> D;

  cout << (int)(L - max(ceil((double)A / C), ceil((double)B / D)));
}