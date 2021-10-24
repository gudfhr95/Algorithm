#include <iostream>
#include <vector>

using namespace std;

int gather(vector<int> &weights) {
  if (weights.size() == 2) return 0;

  int result = -987654321;
  for (int i = 1; i < weights.size() - 1; i++) {
    int sum = weights[i - 1] * weights[i + 1];

    vector<int> erased(weights);
    erased.erase(erased.begin() + i);

    sum += gather(erased);

    result = max(result, sum);
  }

  return result;
}

int main() {
  int N;

  cin >> N;

  vector<int> weights;
  for (int i = 0; i < N; i++) {
    int w;

    cin >> w;

    weights.push_back(w);
  }

  cout << gather(weights);
}