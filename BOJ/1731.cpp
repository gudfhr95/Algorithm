#include <iostream>
#include <vector>

using namespace std;

bool isArithmetic(vector<int> seq) {
  if ((seq[0] - seq[1]) == (seq[1] - seq[2]))
    return true;
  else
    return false;
}

int main() {
  int N, n;
  vector<int> seq;

  cin >> N;

  while (N--) {
    cin >> n;
    seq.push_back(n);
  }

  if (isArithmetic(seq))
    cout << seq[seq.size() - 1] + (seq[1] - seq[0]);
  else
    cout << seq[seq.size() - 1] * (seq[1] / seq[0]);
}