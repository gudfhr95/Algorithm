#include <cstring>
#include <iostream>

using namespace std;

long long cache[61][61];

long long pill(int one, int half) {
  if (one == 0) return 1;

  long long &ret = cache[one][half];

  if (ret != -1) return ret;

  ret = 0;
  if (one > 0) {
    ret += pill(one - 1, half + 1);
  }
  if (half > 0) {
    ret += pill(one, half - 1);
  }
  return ret;
}

int main() {
  int n;

  while (true) {
    cin >> n;

    if (n == 0) break;

    memset(cache, -1, sizeof(cache));

    cout << pill(n - 1, 1) << '\n';
  }
}