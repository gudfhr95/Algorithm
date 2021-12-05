#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool mix[201][201];
int result = 0;

bool check(vector<int> icecreams) {
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      int i1 = icecreams[i];
      int i2 = icecreams[j];
      if (i1 == i2) return false;

      if (mix[i1][i2]) return false;
    }
  }

  return true;
}

void eat(vector<int> icecreams) {
  if (icecreams.size() == 3) {
    if (check(icecreams)) {
      result++;
    }
    return;
  }

  int i = icecreams.size() == 0 ? 1 : icecreams.back() + 1;
  for (; i <= N; i++) {
    vector<int> ic(icecreams);
    ic.push_back(i);

    eat(ic);
  }
}

int main() {
  cin >> N >> M;

  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;

    mix[a][b] = true;
    mix[b][a] = true;
  }

  eat({});

  cout << result;
}