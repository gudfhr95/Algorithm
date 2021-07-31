#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, n;
  vector<int> devisors;

  cin >> N;

  while (N--) {
    cin >> n;
    devisors.push_back(n);
  }

  sort(devisors.begin(), devisors.end());

  if (N == 1)
    cout << pow(devisors[0], 2);
  else
    cout << devisors.front() * devisors.back();
}