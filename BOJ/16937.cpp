#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int H, W, N;
vector<pair<int, int>> stickers;

bool fit(int r1, int c1, int r2, int c2) {
  if (max(r1, r2) <= H && c1 + c2 <= W) {
    return true;
  } else if (max(r1, c2) <= H && c1 + r2 <= W) {
    return true;
  } else if (max(c1, c2) <= H && r1 + r2 <= W) {
    return true;
  } else if (max(c1, r2) <= H && r1 + c2 <= W) {
    return true;
  } else if (max(r1, r2) <= W && c1 + c2 <= H) {
    return true;
  } else if (max(r1, c2) <= W && c1 + r2 <= H) {
    return true;
  } else if (max(c1, c2) <= W && r1 + r2 <= H) {
    return true;
  } else if (max(c1, r2) <= W && r1 + c2 <= H) {
    return true;
  }

  return false;
}

int main() {
  cin >> H >> W >> N;

  int r, c;
  for (int i = 0; i < N; i++) {
    cin >> r >> c;

    stickers.push_back({r, c});
  }

  int result = 0;
  int r1, c1, r2, c2;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;

      tie(r1, c1) = stickers[i];
      tie(r2, c2) = stickers[j];

      if (fit(r1, c1, r2, c2)) {
        result = max(result, (r1 * c1) + (r2 * c2));
      }
    }
  }

  cout << result;
}